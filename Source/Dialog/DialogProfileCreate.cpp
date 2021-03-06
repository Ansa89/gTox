/**
    gTox a GTK-based tox-client - https://github.com/KoKuToru/gTox.git

    Copyright (C) 2014  Luca Béla Palkovics
    Copyright (C) 2014  Maurice Mohlek

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
 **/
#include "DialogProfileCreate.h"
#include "Tox/Toxmm.h"
#include <glibmm/i18n.h>

DialogProfileCreate::DialogProfileCreate(BaseObjectType* cobject, gToxBuilder builder,
                                         const Glib::ustring& path):
    Gtk::Assistant(cobject), m_builder(builder), m_aborted(true), m_path(path) {

    property_resizable() = false;
    set_size_request(800, 600);
    set_position(Gtk::WindowPosition::WIN_POS_CENTER_ALWAYS);

    m_builder.get_widget("assistant_username", m_username);
    m_builder.get_widget("assistant_statusmessage", m_status);
    m_builder.get_widget("assistant_logging", m_logging);
    m_builder.get_widget("assistant_file_tox", m_file_tox);
    m_builder.get_widget("assistant_file_gtox", m_file_gtox);

    if (m_username && m_file_tox && m_file_gtox) {
        auto w = m_builder.get_widget<Gtk::Widget>("assistant_first_page");
        m_username->signal_changed().connect([this, w]() {
            if (!m_username->get_text().empty()) {
                int i = 0;
                do {
                    auto name = m_username->get_text() + (i?std::to_string(i):"");
                    m_file_tox->set_text(Glib::build_filename(m_path, name + ".tox"));
                    m_file_gtox->set_text(Glib::build_filename(m_path, name + ".gtox"));
                    i += 1;
                } while (Glib::file_test(m_file_tox->get_text(), Glib::FILE_TEST_IS_REGULAR) ||
                         Glib::file_test(m_file_gtox->get_text(), Glib::FILE_TEST_IS_REGULAR));

                if (w) {
                    set_page_complete(*w, true);
                }
            } else {
                m_file_tox->set_text("");
                m_file_gtox->set_text("");
                if (w) {
                    set_page_complete(*w, false);
                }
            }
        });
    }
}

DialogProfileCreate* DialogProfileCreate::create(const Glib::ustring& path) {
    return gToxBuilder(Gtk::Builder::create_from_resource("/org/gtox/ui/dialog_assistant.ui"))
            .get_widget_derived<DialogProfileCreate>("dialog_assistant", path);
}

DialogProfileCreate::~DialogProfileCreate() {
}


int DialogProfileCreate::on_next(int) {
    return 0;
}

void DialogProfileCreate::on_cancel() {
    m_path.clear();
    hide();
}

void DialogProfileCreate::on_apply() {
    m_path = m_file_tox->get_text().substr(0, m_file_tox->get_text().find_last_of("."));
    Toxmm instance;
    instance.open(m_path);
    instance.set_name(m_username->get_text());
    instance.set_status_message(m_status->get_text());
    instance.database().open(m_path, true);
    instance.database().config_set("LOG_CHAT", m_logging->get_active());
    instance.save();
    m_aborted = false;
    hide();
}

void DialogProfileCreate::on_close() {

}

bool DialogProfileCreate::is_aborted() {
    return m_aborted;
}

Glib::ustring DialogProfileCreate::get_path() {
    return m_path;
}
