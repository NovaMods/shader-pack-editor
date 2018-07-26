//
// Created by jannis on 25.07.18.
//

#include <iostream>

#include "application.hpp"
#include "../window/launcher_window.hpp"
#include "../util/stream_utils.hpp"

#ifdef __cplusplus
extern "C" {
#include "../../resources/resources.h"
};
#endif

namespace shader_editor {
    void application::create(int argc, char **argv) {
        instance.reset(new application(argc, argv));
    }

    application::application(int argc, char **argv) {
        gtk_application = Gtk::Application::create(argc, argv, "com.continuum.nova.shadereditor");
        Glib::wrap(nova_get_resource())->register_global();
    }

    int application::run() {
        auto config_dir = Gio::File::create_for_path("config");
        if(!config_dir->query_exists() || config_dir->query_file_type() != Gio::FileType::FILE_TYPE_DIRECTORY) {
            if(!config_dir->make_directory()) {
                Gtk::MessageDialog dialog("Failed to create config directory!", false, Gtk::MESSAGE_ERROR);
                dialog.set_title("Config");
                dialog.run();
                return EXIT_FAILURE;
            }
        }
        auto settings_schema_file = config_dir->get_child("gschemas.compiled");
        if(!settings_schema_file->query_exists() || settings_schema_file->query_file_type() != Gio::FileType::FILE_TYPE_REGULAR) {
            shader_editor::stream_utils::copy(Gio::Resource::open_stream_global("/com/continuum/shaderpackeditor/schemas/gschemas.compiled"),
                                              settings_schema_file->append_to());
        }

        {
            GError *err = nullptr;
            // At the moment this functionality is not implemented in giomm, so wrap the C object
            Glib::RefPtr<Gio::SettingsSchemaSource> schema_source =
                    Glib::wrap(g_settings_schema_source_new_from_directory("config", g_settings_schema_source_get_default(), FALSE, &err));
            if(err) {
                Gtk::MessageDialog dialog("Failed to load config schema!", false, Gtk::MESSAGE_ERROR);
                dialog.set_title("Config");
                dialog.run();
                return EXIT_FAILURE;
            }

            auto schema = schema_source->lookup("com.continuum.shaderpackeditor", false);
            if(!schema) {
                Gtk::MessageDialog dialog("Failed to lookup config schema!", false, Gtk::MESSAGE_ERROR);
                dialog.set_title("Config");
                dialog.run();
                return EXIT_FAILURE;
            }

            settings = Glib::wrap(g_settings_new_full(schema->gobj(), nullptr, nullptr));
            std::cout << settings->get_string("some-value") << std::endl;
            settings->set_string("some-value", "A new value");
        }

        shader_editor::launcher_window window;
        window.show_all();
        return gtk_application->run(window);
    }

    Glib::RefPtr<Gio::Settings> application::get_settings() {
        return settings;
    }
}