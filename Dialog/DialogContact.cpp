#include "DialogContact.h"

DialogContact::DialogContact():
    m_icon_attach("/source/gTox/Icons/chat_attach.svg"),
    m_icon_detach("/source/gTox/Icons/chat_detach.svg") //we will need to embed it
{

    this->set_border_width(1);
    this->set_default_geometry(/*300*/800, 600);
    this->set_position(Gtk::WindowPosition::WIN_POS_CENTER);

    //Setup titlebar
    m_headerbar_contact.set_title("Contacts");
    m_headerbar_contact.set_subtitle("KoKuToru");
    m_headerbar_contact.set_show_close_button();

    m_headerbar_chat.set_title("Chat");
    m_headerbar_chat.set_subtitle("with DemoUser");

    m_btn_xxtach.set_image(m_icon_detach);

    m_headerbar_btn_right.get_style_context()->add_class("linked");
    m_headerbar_btn_right.add(m_btn_xxtach);
    m_headerbar_chat.pack_end(m_headerbar_btn_right);

    m_header_paned.pack1(m_headerbar_chat  , true, true);
    m_header_paned.pack2(m_headerbar_contact, true, false);

    this->set_titlebar(m_header_paned);

    //Setup content
    m_paned.pack1(m_chat, true, true);
    m_paned.pack2(m_contact, true, true);
    this->add(m_paned);

    //Connect properties C++ version ?
    g_object_bind_property(m_header_paned.gobj(), "position",
                           m_paned.gobj(),        "position",
                           GBindingFlags(G_BINDING_DEFAULT | G_BINDING_BIDIRECTIONAL | G_BINDING_SYNC_CREATE));

    //events
    m_btn_xxtach.signal_clicked().connect(sigc::mem_fun(this, &DialogContact::detachChat));

    this->show_all();
}

DialogContact::~DialogContact() {

}

void DialogContact::detachChat() {
    this->property_gravity() = Gdk::GRAVITY_NORTH_WEST;
    int x,y;
    this->get_position(x, y);
    this->property_gravity() = Gdk::GRAVITY_NORTH_EAST;
    int w,h;
    this->get_size(w, h);
    int hw = m_headerbar_chat.get_width();
    w -= hw;
    this->resize(w, h);

    m_header_paned.remove(m_headerbar_chat);
    m_paned.remove(m_chat);

    m_chat_dialog.move(x, y);
    m_chat_dialog.resize(hw+52, h); //too small why ?
    m_chat_dialog.show();
}
