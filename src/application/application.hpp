//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_APPLICATION_HPP
#define NOVASHADEREDITORGTK_APPLICATION_HPP

#include <memory>
#include <gtkmm.h>

namespace shader_editor {
    class application {
    public:
        static std::shared_ptr<shader_editor::application> instance;
        static void create(int argc, char **argv);

        int run();
        Glib::RefPtr<Gio::Settings> get_settings();

    private:
        Glib::RefPtr<Gtk::Application> gtk_application;
        Glib::RefPtr<Gio::Settings> settings;

        application(int argc, char **argv);
    };
}


#endif //NOVASHADEREDITORGTK_APPLICATION_HPP
