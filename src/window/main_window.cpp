//
// Created by jannis on 04.08.18.
//

#include "main_window.hpp"
#include "../application/application.hpp"

namespace shader_editor {
    main_window::main_window() : glade_window("/com/continuum/shaderpackeditor/ui/main_ui.glade") {
        setup();
    }

    void main_window::setup() {
        get_widget("window", window);
        application::instance->get_current_project()->get_file_tree()->setup_treeview(get_widget<Gtk::TreeView>("project_file_treeview"));
    }

    Gtk::Window* main_window::get_window() {
        return window.get();
    }
}