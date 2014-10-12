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
#ifndef DIALOGCONTACT_H
#define DIALOGCONTACT_H

#include <gtkmm.h>

#include "Widget/WidgetChat.h"
#include "Widget/WidgetContact.h"
#include "Widget/WidgetNotification.h"
#include "Popover/PopoverStatus.h"
#include "Popover/PopoverSettings.h"
#include "Popover/PopoverAddContact.h"

#include "DialogChat.h"

//contact list with pinned chat
class DialogContact: public Gtk::Window {
    private:
        static DialogContact* m_instance;

        Gtk::Paned     m_header_paned;
        Gtk::HeaderBar m_headerbar_chat;
        Gtk::HeaderBar m_headerbar_contact;

        Gtk::Paned     m_paned;

        Gtk::Image     m_icon_attach;
        Gtk::Image     m_icon_detach;
        Gtk::Image     m_icon_settings;
        Gtk::Image     m_icon_status;
        Gtk::Image     m_icon_add;

        Gtk::Button    m_btn_xxtach;
        Gtk::Button    m_btn_status;
        Gtk::Button    m_btn_settings;
        Gtk::Button    m_btn_add;

        Gtk::Box       m_headerbar_chat_box_left;
        Gtk::Box       m_headerbar_contact_box_left;
        Gtk::Box       m_headerbar_contact_box_right;

        Gtk::Box       m_chat;

        Gtk::VBox      m_vbox;

        WidgetContact m_contact;
        WidgetNotification m_notification;

        DialogChat     m_chat_dialog; //probably a list in the future

        sigc::connection m_update_interval;

        std::string m_config_path;

        PopoverStatus   m_popover_status;
        PopoverSettings m_popover_settings;
        PopoverAddContact m_popover_add;

        DialogContact(const std::string& config_path);

    public:
        ~DialogContact();
        static void init(const std::string& config_path);
        static DialogContact& instance();
        static void destroy();

        void activate_chat(Tox::FriendNr nr);
        void set_status(Tox::EUSERSTATUS status_code);
        void exit();
        void add_contact(Tox::FriendNr nr);
        void change_name(Glib::ustring name, Glib::ustring msg);

    protected:
        void detach_chat();
        bool update();
        WidgetChat* get_chat(Tox::FriendNr nr);

};

#endif
