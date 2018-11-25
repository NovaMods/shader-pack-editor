//
// Created by jannis on 08.08.18.
//

#include "generic_file_editor.hpp"
#include <gtksourceviewmm.h>
#include <iostream>

namespace shader_editor {
    generic_file_editor::generic_file_editor(const Glib::RefPtr<Gio::File> &file) : file(file), source_buffer(Gsv::Buffer::create()), source_view(source_buffer) {
        source_file = gtk_source_file_new();
        gtk_source_file_set_location(source_file, file->gobj());
        gtk_source_file_check_file_on_disk(source_file);
        source_loader = gtk_source_file_loader_new(source_view.get_source_buffer()->gobj(), source_file);
        gtk_source_file_loader_load_async(source_loader, G_PRIORITY_DEFAULT, nullptr, nullptr, nullptr, nullptr, nullptr,
                                          nullptr);

        file_monitor = file->monitor_file();
        file_monitor->signal_changed().connect(sigc::mem_fun(this, &generic_file_editor::on_file_changed));

        set_title(file->get_basename());
    }

    generic_file_editor::~generic_file_editor() {}

    Gtk::Widget *generic_file_editor::get_view() {
        return &source_view;
    }

    void generic_file_editor::on_file_changed(const Glib::RefPtr<Gio::File>& file ,const Glib::RefPtr<Gio::File>& other_file, Gio::FileMonitorEvent event) {
        gtk_source_file_check_file_on_disk(source_file);
    }
}