//
// Created by jannis on 25.07.18.
//

#include "application.hpp"

namespace shader_editor {
    void application::create(int argc, char **argv) {
        instance = std::make_shared<application>(argc, argv);
    }

    application::application(int argc, char **argv) {
        gtk_application = Gtk::Application::create(argc, argv, "com.continuum.nova.shadereditor");
    }

    int application::run() {
        return 0;
    }
}