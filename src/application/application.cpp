//
// Created by jannis on 25.07.18.
//

#include <iostream>

#include <giomm/settings.h>
#include <glibmm/i18n.h>
#include "application.hpp"
#include "../window/launcher_window.hpp"
#include "../util/stream_utils.hpp"
#include "../window/main_window.hpp"
#include <cstdlib>

#ifdef __cplusplus
extern "C" {
#endif
#include "../../resources/resources.h"
#ifdef __cplusplus
}
#endif

#define COPY_LANG(lang) \
stream_utils::copy_resource_to_file("/com/continuum/shaderpackeditor/language/" #lang "/LC_MESSAGES/editor.mo",\
    language_dir->get_child(#lang "/LC_MESSAGES/editor.mo"), true)

namespace shader_editor {
    void application::create(int argc, char **argv) {
        instance.reset(new application(argc, argv));
    }

    application::application(int argc, char **argv) {
        gtk_application = Gtk::Application::create(argc, argv, "com.continuum.nova.shadereditor");
        g_resources_register(nova_get_resource());
    }

    int application::run() {
        auto language_dir = Gio::File::create_for_path("language");
        if(!language_dir->query_exists() || language_dir->query_file_type() != Gio::FileType::FILE_TYPE_DIRECTORY) {
            if(!language_dir->make_directory()) {
                Gtk::MessageDialog dialog("Failed to create language directory!", false, Gtk::MESSAGE_ERROR);
                dialog.set_title("Language");
                dialog.run();
                return EXIT_FAILURE;
            }
        }

        COPY_LANG(de);

        setlocale(LC_ALL, "");
        bindtextdomain("editor", language_dir->get_path().c_str());
        textdomain("editor");

        auto config_dir = Gio::File::create_for_path("config");
        if(!config_dir->query_exists() || config_dir->query_file_type() != Gio::FileType::FILE_TYPE_DIRECTORY) {
            if(!config_dir->make_directory()) {
                Gtk::MessageDialog dialog(_("Failed to create config directory!"), false, Gtk::MESSAGE_ERROR);
                dialog.set_title(_("Config"));
                dialog.run();
                return EXIT_FAILURE;
            }
        }
        stream_utils::copy_resource_to_file("/com/continuum/shaderpackeditor/schemas/gschemas.compiled",
                                                           config_dir->get_child("gschemas.compiled"), true);

        {
            GError *err = nullptr;
            // At the moment this functionality is not implemented in giomm, so wrap the C object
            Glib::RefPtr<Gio::SettingsSchemaSource> schema_source =
                    Glib::wrap(g_settings_schema_source_new_from_directory("config", g_settings_schema_source_get_default(), FALSE, &err));
            if(err) {
                Gtk::MessageDialog dialog(_("Failed to load config schema!"), false, Gtk::MESSAGE_ERROR);
                dialog.set_title("Config");
                dialog.run();
                return EXIT_FAILURE;
            }

            auto schema = schema_source->lookup("com.continuum.shaderpackeditor", false);
            if(!schema) {
                Gtk::MessageDialog dialog(_("Failed to lookup config schema!"), false, Gtk::MESSAGE_ERROR);
                dialog.set_title(_("Config"));
                dialog.run();
                return EXIT_FAILURE;
            }

            settings = Glib::wrap(g_settings_new_full(schema->gobj(), nullptr, nullptr));
        }

        {
            launcher_window launcher_window;
            dynamic_cast<Gtk::Dialog *>(launcher_window.get_window())->run();
        }

        return load_current_project();
    }

    Glib::RefPtr<Gio::Settings> application::get_settings() {
        return settings;
    }

    void application::set_current_project(const std::shared_ptr<shader_pack_project> &project) {
        current_project = project;
    }

    int application::load_current_project() {
        if(!current_project) {
            return EXIT_SUCCESS;
        }

        current_project->on_load();
        main_window window;
        return gtk_application->run(*window.get_window());
    }

    std::shared_ptr<shader_pack_project> application::get_current_project() {
        return current_project;
    }
}