//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_APPLICATION_HPP
#define NOVASHADEREDITORGTK_APPLICATION_HPP

#include <memory>
#include <gtkmm.h>
#ifdef GTK_SOURCE_H_INSIDE
#   undef GTK_SOURCE_H_INSIDE
#endif
#include <gtksourceview/gtksource.h>
#include "../project/shader_pack_project.hpp"
#include "../window/main_window.hpp"
#include <sigc++/sigc++.h>
#include <gtksourceviewmm.h>

namespace shader_editor {
    class application {
    public:
        typedef sigc::signal1<void, GtkSourceStyleScheme *> signal_theme_changed_t;

    private:
        Glib::RefPtr<Gtk::Application> gtk_application;
        Glib::RefPtr<Gio::Settings> settings;
        std::shared_ptr<shader_pack_project> current_project;
        std::shared_ptr<main_window> window;
        GtkSourceStyleScheme *source_style_scheme;
        Glib::RefPtr<Gsv::LanguageManager> programming_language_manager;

        application(int argc, char **argv);

        int load_current_project();

        signal_theme_changed_t _signal_theme_changed;

    public:
        static std::shared_ptr<application> instance;
        static void create(int argc, char **argv);

        int run();
        Glib::RefPtr<Gio::Settings> get_settings();

        void set_current_project(const std::shared_ptr<shader_pack_project> &project);
        std::shared_ptr<shader_pack_project> get_current_project();
        std::shared_ptr<main_window> get_window();

        signal_theme_changed_t signal_theme_changed();

        void set_source_style_scheme(GtkSourceStyleScheme *scheme);
        GtkSourceStyleScheme *get_source_style_scheme();

        Glib::RefPtr<Gsv::LanguageManager> get_programming_language_manager();
    };
}


#endif //NOVASHADEREDITORGTK_APPLICATION_HPP
