//
// Created by jannis on 07.08.18.
//

#include <iostream>
#include "project_file_tree.hpp"
#include "../util/file_utils.hpp"

namespace shader_editor {
    project_file_tree::project_file_tree(const Glib::ustring &root) : root(Gio::File::create_for_path(root)), pixbuf_renderer(), text_renderer(), file_column("File"),
                                                                      store(Gtk::TreeStore::create(column_templates))
    {}

    void project_file_tree::stop_monitoring() {
        for(const auto &[file, monitor] : file_monitors) {
            stop_monitoring(Gio::File::create_for_path(file));
        }
    }

    void project_file_tree::add_file_to_tree(const Glib::RefPtr<Gio::File> &file) {
        if(file->get_path() == root->get_path()) {
            return;
        }

        if(file->get_parent()->get_path() == root->get_path()) {
            auto row = *(store->append());
            row[column_templates.file_column] = file->query_info()->get_display_name();
            row[column_templates.icon_column] = file_utils::get_icon_for_file(file, 16);
            rows.insert(std::make_pair(file->get_path(), row));
        } else {
            if(rows.find(file->get_parent()->get_path()) == rows.end()) {
                g_warning(Glib::ustring::compose("Not adding %1 because the parent %2 is not in rows", file->get_path(), file->get_parent()->get_path()).c_str());
            } else {
                auto parent = rows.at(file->get_parent()->get_path());
                auto row = *(store->append(parent.children()));
                row[column_templates.file_column] = file->query_info()->get_display_name();
                row[column_templates.icon_column] = file_utils::get_icon_for_file(file, 16);
                rows.insert(std::make_pair(file->get_path(), row));
            }
        }
    }

    void project_file_tree::start_monitoring(const Glib::RefPtr<Gio::File> &file) {
        if(file_monitors.find(file->get_path()) == file_monitors.end()) {
            if(file->query_file_type() != Gio::FileType::FILE_TYPE_DIRECTORY) {
                throw std::runtime_error(Glib::ustring::compose("Tried to monitor non directory %1", file->get_path()));
            }

            auto monitor = file->monitor_directory();
            monitor->signal_changed().connect(sigc::mem_fun(this, &project_file_tree::file_updated));
            file_monitors.insert(std::make_pair(file->get_path(), monitor));
        }
    }

    void project_file_tree::remove_file_from_tree(const std::string &path) {
        if(rows.find(path) != rows.end()) {
            auto row = rows.at(path);
            store->erase(row);
        }
    }

    void project_file_tree::stop_monitoring(const Glib::RefPtr<Gio::File> &file) {
        stop_monitoring(file->get_path());
    }

    void project_file_tree::stop_monitoring(const std::string &path) {
        if(file_monitors.find(path) != file_monitors.end()) {
            auto monitor = file_monitors.at(path);
            monitor->cancel();
            monitor.reset();
            file_monitors.erase(path);
        }
    }

    void project_file_tree::setup_treeview(Gtk::TreeView *view) {
        view->set_model(store);

        file_column.pack_start(pixbuf_renderer, false);
        file_column.pack_start(text_renderer, true);
        file_column.add_attribute(text_renderer, "text", 0);
        file_column.add_attribute(pixbuf_renderer, "pixbuf", 1);

        view->append_column(file_column);
    }

    void project_file_tree::file_updated(Glib::RefPtr<Gio::File> file, Glib::RefPtr<Gio::File> other_file, Gio::FileMonitorEvent event) {
        std::cout << ">>> File change event >>>\n";
        if (file) {
            std::cout << "File: " << file->get_path() << "\n";
        }
        if (other_file) {
            std::cout << "Other file: " << other_file->get_path() << "\n";
        }
        std::cout << "Event: " << event << "\n";
        std::cout << "<<< File change event <<<" << std::endl;

        if(event == Gio::FileMonitorEvent::FILE_MONITOR_EVENT_CREATED) {
            if(file->query_file_type() == Gio::FileType::FILE_TYPE_DIRECTORY) {
                start_monitoring(file);
            }
            add_file_to_tree(file);
        } else if(event == Gio::FileMonitorEvent::FILE_MONITOR_EVENT_DELETED) {
            stop_monitoring(file);
            remove_remaining(file);
            remove_file_from_tree(file->get_path());
        }
    }

    /*
     * Take the following:
     * dir1/dir2/file
     * if dir1 is deleted we do not receive events for dir2 nor file being deleted, so clean up
     */
    void project_file_tree::remove_remaining(const Glib::RefPtr<Gio::File> &deleted_root) {
        for(const auto &[path, monitor] : file_monitors) {
            if(path.find(deleted_root->get_path()) == 0) {
                stop_monitoring(path);
            }
        }
    }

    void project_file_tree::reload() {
        store->clear();
        add_directory_recursive(root);
    }

    void project_file_tree::add_directory_recursive(const Glib::RefPtr<Gio::File> &root) {
        start_monitoring(root);
        add_file_to_tree(root);

        auto enumerator = root->enumerate_children();
        Glib::RefPtr<Gio::FileInfo> file_info;
        while(file_info = enumerator->next_file()) {
            auto file = enumerator->get_child(file_info);
            if(file_info->get_file_type() == Gio::FileType::FILE_TYPE_DIRECTORY) {
                add_directory_recursive(file);
            } else {
                add_file_to_tree(file);
            }
        }
    }

}