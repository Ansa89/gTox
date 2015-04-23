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

#ifndef FIRSTSTARTASSISTANT_H
#define FIRSTSTARTASSISTANT_H

#include <gtkmm.h>

class DialogProfileCreate : public Gtk::Assistant {
  private:
    const Glib::RefPtr<Gtk::Builder> m_builder;
    bool m_aborted;
    Glib::ustring m_path;

    Gtk::Entry  *m_username = nullptr;
    Gtk::Entry  *m_status = nullptr;
    Gtk::Switch *m_logging = nullptr;
    Gtk::Entry  *m_file_tox = nullptr;
    Gtk::Entry  *m_file_gtox = nullptr;

    int on_next(int page);
    void on_cancel();
    void on_close();
    void on_apply();

    void set_path(const Glib::ustring& path);

  public:
    ~DialogProfileCreate();

    DialogProfileCreate(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    static DialogProfileCreate* create(const Glib::ustring& path);

    bool is_aborted();
    Glib::ustring get_path();
};

#endif
