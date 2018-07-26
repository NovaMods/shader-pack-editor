//
// Created by jannis on 25.07.18.
//

#include <iostream>
#include "application.hpp"
#include "../window/launcher_window.hpp"
extern "C" {
#include "../../resources/resources.h"
};

namespace shader_editor {
    void application::create(int argc, char **argv) {
        instance.reset(new application(argc, argv));
    }

    application::application(int argc, char **argv) {
        gtk_application = Gtk::Application::create(argc, argv, "com.continuum.nova.shadereditor");
        Glib::wrap(nova_get_resource())->register_global();
    }

    int application::run() {
        shader_editor::launcher_window window;
        window.show_all();
        return gtk_application->run(window);
    }
}