//
// Created by jannis on 03.08.18.
//

#ifndef NOVA_SHADER_EDITOR_FILE_UTIL_HPP
#define NOVA_SHADER_EDITOR_FILE_UTIL_HPP

#include <glib/gi18n.h>
#include <gtkmm.h>
#include <utility>
#include "../application/application.hpp"

namespace shader_editor {
    class file_utils {
    public:
        static void ensure_file(const Glib::RefPtr<Gio::File> &file) {
            if(file->query_exists() && file->query_file_type() == Gio::FileType::FILE_TYPE_REGULAR) {
                return;
            }

            ensure_directory(file->get_parent());
            if(!file->create_file()) {
                throw file_creation_error(Glib::ustring::compose(_("Failed to create file %1"), file->get_path()));
            }
        }

        static void ensure_directory(const Glib::RefPtr<Gio::File> &dir) {
            if(dir->query_exists() && dir->query_file_type() == Gio::FileType::FILE_TYPE_DIRECTORY) {
                return;
            }

            if(!dir->make_directory_with_parents()) {
                throw file_creation_error(Glib::ustring::compose(_("Failed to create directory %1"), dir->get_path()));
            }
        }

        static Glib::RefPtr<Gdk::Pixbuf> get_icon_for_file(const Glib::RefPtr<Gio::File> &file, int size) {
            Glib::RefPtr<Gtk::IconTheme> theme;
            if(application::instance && application::instance->get_window()) {
                theme = Gtk::IconTheme::get_for_screen(application::instance->get_window()->get_window()->get_screen());
            } else {
                theme = Gtk::IconTheme::get_default();
            }
            auto info = theme->lookup_icon(file->query_info("standard::icon")->get_icon(), size, Gtk::IconLookupFlags::ICON_LOOKUP_USE_BUILTIN);
            if(info) {
                return info.load_icon();
            } else if(file->query_file_type() == Gio::FileType::FILE_TYPE_DIRECTORY) {
                return theme->load_icon("folder", size);
            } else {
                return theme->load_icon("document", size);
            }
        }

        class file_creation_error : public std::exception {
        private:
            Glib::ustring msg;

        public:
            explicit file_creation_error(Glib::ustring msg) : msg(std::move(msg)) {}

            const char *what() const noexcept override {
                return msg.c_str();
            }
        };
    };
}

#endif //NOVA_SHADER_EDITOR_FILE_UTIL_HPP
