//
// Created by jannis on 04.08.18.
//

#include "main_window.hpp"

namespace shader_editor {
    main_window::main_window() : glade_window("/com/continuum/shaderpackeditor/ui/main_ui.glade") {
        setup();
    }

    void main_window::setup() {
        get_widget("window", window);
    }

    Gtk::Window* main_window::get_window() {
        return window.get();
    }
}