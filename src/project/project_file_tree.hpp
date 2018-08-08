//
// Created by jannis on 07.08.18.
//

#ifndef NOVA_SHADER_EDITOR_PROJECT_FILE_TREE_HPP
#define NOVA_SHADER_EDITOR_PROJECT_FILE_TREE_HPP

#include <gtkmm.h>
#include <string>

namespace shader_editor {
    class project_file_tree {
    private:
    class ProjectColumnRecord : public Gtk::TreeModel::ColumnRecord {
        public:
            ProjectColumnRecord() {
                add(file_column);
                add(icon_column);
            }

            Gtk::TreeModelColumn<Glib::ustring> file_column;
            Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf>> icon_column;
        };
        ProjectColumnRecord column_templates;

        Gtk::TreeViewColumn file_column;

        Gtk::CellRendererPixbuf pixbuf_renderer;
        Gtk::CellRendererText text_renderer;

        Glib::RefPtr<Gio::File> root;
        Glib::RefPtr<Gtk::TreeStore> store;

        std::map<std::string, Glib::RefPtr<Gio::FileMonitor>> file_monitors;
        std::map<std::string, Gtk::TreeModel::Row> rows;

        void add_file_to_tree(const Glib::RefPtr<Gio::File> &file);
        void start_monitoring(const Glib::RefPtr<Gio::File> &file);

        void remove_file_from_tree(const std::string &path);
        void stop_monitoring(const Glib::RefPtr<Gio::File> &file);
        void stop_monitoring(const std::string &path);

        void remove_remaining(const Glib::RefPtr<Gio::File> &deleted_root);

        void add_directory_recursive(const Glib::RefPtr<Gio::File> &root);

    public:
        explicit project_file_tree(const Glib::ustring &root);

        void stop_monitoring();
        void setup_treeview(Gtk::TreeView *view);

        void file_updated(Glib::RefPtr<Gio::File> file, Glib::RefPtr<Gio::File> other_file, Gio::FileMonitorEvent event);

        void reload();
    };
}


#endif //NOVA_SHADER_EDITOR_PROJECT_FILE_TREE_HPP
