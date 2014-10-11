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
#include "DialogChat.h"
#include "Generated/icon.h"

DialogChat::DialogChat():
    m_icon_attach(ICON::load_icon(ICON::chat_attach))
{
    this->set_border_width(1);
    this->set_default_geometry(256, 256);
    this->set_position(Gtk::WindowPosition::WIN_POS_NONE);

    //Setup titlebar
    m_header.set_title("Chat");
    m_header.set_subtitle("with DemoUser");
    m_header.set_show_close_button();

    m_btn_xxtach.set_image(m_icon_attach);

    m_headerbar_btn_left.get_style_context()->add_class("linked");
    m_headerbar_btn_left.add(m_btn_xxtach);
    m_header.pack_start(m_headerbar_btn_left);

    this->set_titlebar(m_header);

    //Setup content
    this->add(m_chat);
}

DialogChat::~DialogChat() {

}

void DialogChat::show() {
    this->show_all();
}
