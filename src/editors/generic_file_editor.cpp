//
// Created by jannis on 08.08.18.
//

#include "generic_file_editor.hpp"
#include "../application/application.hpp"
#include <iostream>

namespace shader_editor {
    generic_file_editor::generic_file_editor(const Glib::RefPtr<Gio::File> &file) : file(file), source_view(GTK_SOURCE_VIEW(gtk_source_view_new())) {
        source_buffer = GTK_SOURCE_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(source_view)));
        source_file = gtk_source_file_new();
        gtk_source_file_set_location(source_file, file->gobj());
        gtk_source_file_check_file_on_disk(source_file);
        source_loader = gtk_source_file_loader_new(source_buffer, source_file);
        gtk_source_file_loader_load_async(source_loader, G_PRIORITY_DEFAULT, nullptr, nullptr, nullptr, nullptr, nullptr,
                                          nullptr);

        file_monitor = file->monitor_file();
        file_monitor->signal_changed().connect(sigc::mem_fun(this, &generic_file_editor::on_file_changed));

        set_title(file->get_basename());

        theme_change_connection = application::instance->signal_theme_changed().connect([&](GtkSourceStyleScheme *scheme){
           gtk_source_buffer_set_style_scheme(source_buffer, scheme);
        });
        gtk_source_buffer_set_style_scheme(source_buffer, application::instance->get_source_style_scheme());

        auto languageId = file->get_basename().substr(file->get_basename().find_last_of('.') + 1);
        auto *language = gtk_source_language_manager_get_language(application::instance->get_programming_language_manager(), languageId.c_str());
        if(language) {
            gtk_source_buffer_set_language(source_buffer, language);
        }
        gtk_source_buffer_set_highlight_syntax(source_buffer, true);
    }

    generic_file_editor::~generic_file_editor() {
        theme_change_connection.disconnect();
    }

    Gtk::Widget *generic_file_editor::get_view() {
        return Glib::wrap(GTK_WIDGET(source_view));
    }

    void generic_file_editor::on_file_changed(const Glib::RefPtr<Gio::File>& file ,const Glib::RefPtr<Gio::File>& other_file, Gio::FileMonitorEvent event) {
        gtk_source_file_check_file_on_disk(source_file);
    }
}