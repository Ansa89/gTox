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
#include "WidgetContactListItem.h"
#include "WidgetContact.h"
#include "../Tox/Tox.h"

WidgetContactListItem::WidgetContactListItem(WidgetContact* contact, Tox::FriendNr nr): m_contact(contact) {
    m_name.set_text(Tox::instance().get_name(nr));
    m_status.set_text(Tox::instance().get_status_message(nr));

    m_avatar.set_size_request(64, 64);

    m_layout.attach(m_avatar, 0, 0, 1, 2);
    m_layout.attach(m_name, 1, 0, 1, 1);
    m_layout.attach(m_status, 1, 1, 1, 1);

    m_name.set_halign(Gtk::Align::ALIGN_START);
    m_status.set_halign(Gtk::Align::ALIGN_START);

    this->add(m_layout);
}

WidgetContactListItem::~WidgetContactListItem() {

}
