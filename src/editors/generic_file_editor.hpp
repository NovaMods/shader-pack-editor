//
// Created by jannis on 08.08.18.
//

#ifndef NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP
#define NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP

#include "abstract_editor.hpp"
#include <gtksourceviewmm.h>

namespace shader_editor {
    class generic_file_editor : public abstract_editor {
    private:
        Glib::RefPtr<Gio::File> file;
        Glib::RefPtr<Gsv::Buffer> source_buffer;
        Gsv::View source_view;

        GtkSourceFile *source_file = nullptr;
        GtkSourceFileLoader *source_loader = nullptr;

        Glib::RefPtr<Gio::FileMonitor> file_monitor;
        void on_file_changed(const Glib::RefPtr<Gio::File>& file ,const Glib::RefPtr<Gio::File>& other_file, Gio::FileMonitorEvent event);

    public:
        explicit generic_file_editor(const Glib::RefPtr<Gio::File> &file);
        ~generic_file_editor();

        Gtk::Widget *get_view() override;
    };
}


#endif //NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP
