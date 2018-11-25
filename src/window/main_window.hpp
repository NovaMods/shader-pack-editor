//
// Created by jannis on 04.08.18.
//

#ifndef NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP
#define NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP

#include "glade_window.hpp"
#include "../editors/abstract_editor.hpp"
#include <memory>

namespace shader_editor {
    class main_window : public glade_window {
    private:
        std::shared_ptr<Gtk::Window> window;
        void setup();

        Gtk::Notebook *editor_notebook;

        std::map<Glib::ustring, std::pair<std::shared_ptr<abstract_editor>, Gtk::ScrolledWindow *>> editors;

    public:
        explicit main_window();

        Gtk::Window *get_window() override;
        void project_loaded();

        bool has_tab(const Glib::ustring &uuid);
        void set_tab(const Glib::ustring &uuid, std::shared_ptr<abstract_editor> editor);
        bool close_tab(const Glib::ustring &uuid);
    };
}


#endif //NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP
