//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_APPLICATION_HPP
#define NOVASHADEREDITORGTK_APPLICATION_HPP

#include <memory>
#include <gtkmm.h>
#include "../project/shader_pack_project.hpp"
#include "../window/main_window.hpp"

namespace shader_editor {
    class application {
    private:
        Glib::RefPtr<Gtk::Application> gtk_application;
        Glib::RefPtr<Gio::Settings> settings;
        std::shared_ptr<shader_pack_project> current_project;

        application(int argc, char **argv);

        int load_current_project();

        std::shared_ptr<main_window> window;

    public:
        static std::shared_ptr<application> instance;
        static void create(int argc, char **argv);

        int run();
        Glib::RefPtr<Gio::Settings> get_settings();

        void set_current_project(const std::shared_ptr<shader_pack_project> &project);
        std::shared_ptr<shader_pack_project> get_current_project();
        std::shared_ptr<main_window> get_window();
    };
}


#endif //NOVASHADEREDITORGTK_APPLICATION_HPP
