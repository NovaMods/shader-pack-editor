//
// Created by jannis on 08.08.18.
//

#ifndef NOVA_SHADER_EDITOR_ABSTRACT_EDITOR_HPP
#define NOVA_SHADER_EDITOR_ABSTRACT_EDITOR_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>

namespace shader_editor {
    class abstract_editor {
    private:
        sigc::signal<void, Glib::ustring> _signal_title_changed;
        Glib::ustring title = _("Unknown");

    protected:
        void set_title(const Glib::ustring &new_title) {
            title = new_title;
            _signal_title_changed.emit(new_title);
        }

    public:
        virtual Gtk::Widget *get_view() = 0;

        sigc::signal<void, Glib::ustring> signal_title_changed() {
            return _signal_title_changed;
        }

        Glib::ustring get_title() {
            return title;
        }
    };
}

#endif //NOVA_SHADER_EDITOR_ABSTRACT_EDITOR_HPP
