//
// Created by jannis on 01.08.18.
//

#ifndef NOVA_SHADER_EDITOR_GLADE_WINDOW_HPP
#define NOVA_SHADER_EDITOR_GLADE_WINDOW_HPP

#include <gtkmm.h>
#include <iostream>

namespace shader_editor {
    class glade_window {
    protected:
        Glib::RefPtr<Gtk::Builder> content;
        explicit glade_window(const Glib::ustring &resource_name) {
            content = Gtk::Builder::create_from_resource(resource_name);
            content->set_translation_domain("editor");
        }

        template <typename T>
        void get_widget(Glib::ustring name, std::shared_ptr<T> &shared) {
            T *tmp = nullptr;
            content->get_widget<T>(name, tmp);
            shared.reset(tmp);
        }

        template <typename T>
        void get_widget(Glib::ustring name, T *&widget) {
            content->get_widget(name, widget);
        }

        template <typename T>
        T *get_widget(Glib::ustring name) {
            T *ptr = nullptr;
            content->get_widget(name, ptr);
            return ptr;
        }

        public:
            virtual Gtk::Window *get_window() = 0;
    };
}


#endif //NOVA_SHADER_EDITOR_GLADE_WINDOW_HPP
