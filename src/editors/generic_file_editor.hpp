//
// Created by jannis on 08.08.18.
//

#ifndef NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP
#define NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP

#include "abstract_editor.hpp"
#include <gtksourceview/gtksource.h>

namespace shader_editor {
    class generic_file_editor : public abstract_editor {
    private:
        Glib::RefPtr<Gio::File> file;
        GtkSourceBuffer *source_buffer = nullptr;
        GtkSourceView *source_view = nullptr;

        GtkSourceFile *source_file = nullptr;
        GtkSourceFileLoader *source_loader = nullptr;

        Glib::RefPtr<Gio::FileMonitor> file_monitor;
        void on_file_changed(const Glib::RefPtr<Gio::File>& file ,const Glib::RefPtr<Gio::File>& other_file, Gio::FileMonitorEvent event);

        sigc::connection theme_change_connection;
    public:
        explicit generic_file_editor(const Glib::RefPtr<Gio::File> &file);
        ~generic_file_editor();

        Gtk::Widget *get_view() override;
    };
}


#endif //NOVA_SHADER_EDITOR_GENERIC_FILE_EDITOR_HPP
