#include <memory>

//
// Created by jannis on 25.07.18.
//

#include <glib/gi18n.h>
#include <giomm.h>
#include <nlohmann/json.hpp>
#include <vector>

#include "shader_pack_project.hpp"
#include "../util/util.hpp"
#include "../util/file_utils.hpp"

namespace shader_editor {
    type_result<std::shared_ptr<shader_pack_project>> shader_pack_project::from_file(Glib::ustring file_path) {
        auto file = Gio::File::create_for_path(file_path);
        if(!file->query_exists()) {
            return type_result<std::shared_ptr<shader_pack_project>>(Glib::ustring(_("File does not exist")));
        }

        if(file->query_file_type(Gio::FileQueryInfoFlags::FILE_QUERY_INFO_NONE) != Gio::FileType::FILE_TYPE_REGULAR) {
            return type_result<std::shared_ptr<shader_pack_project>>(Glib::ustring(_("File is not a regular file")));
        }

        gsize file_size = static_cast<gsize>(file->query_info("standard::size")->get_size()); // cast because this returns goffset for some reason...
                                                                                              // which is signed... Did you ever see a negative file size?
        auto *buff = new char[file_size + 1];
        auto input_stream = file->read();

        gsize bytes_read;
        input_stream->read_all(buff, file_size, bytes_read);
        if(bytes_read != file_size) {
            return type_result<std::shared_ptr<shader_pack_project>>(
                    Glib::ustring(_("Read bytes didn't match file size, did the file change its size while reading?")));
        }
        buff[file_size] = '\0';
        input_stream->close();

        auto project = from_scratch();
        try {
            nlohmann::json structure = nlohmann::json::parse(buff);
            shader_editor::util::assign_from_json(structure, "name", project->name);
        } catch (const nlohmann::json::parse_error &e) {
            return type_result<std::shared_ptr<shader_pack_project>>(e.what());
        } catch (const shader_editor::util::type_mismatch_exception &e) {
            return type_result<std::shared_ptr<shader_pack_project>>(e.what());
        } catch (const shader_editor::util::missing_value_exception &e) {
            return type_result<std::shared_ptr<shader_pack_project>>(e.what());
        }

        project->root = file->get_parent()->get_path();
        return type_result<std::shared_ptr<shader_pack_project>>(project);
    }

    std::shared_ptr<shader_pack_project> shader_pack_project::from_scratch() {
        std::shared_ptr<shader_pack_project> ptr;
        ptr.reset(new shader_pack_project()); // else its not accessible
        return ptr;
    }

    shader_pack_project::shader_pack_project() {}

    shader_pack_project::~shader_pack_project() {
        file_tree->stop_monitoring();
    }

    void shader_pack_project::save_project_file() {
        auto file = Gio::File::create_for_path(Glib::ustring::compose("%1/project.json", root));
        nlohmann::json structure;
        structure["name"] = name;
        try {
            file_utils::ensure_file(file);
            auto stream = file->replace();
            stream->write(structure.dump());
            stream->close();
        } catch(const file_utils::file_creation_error &e) {
            Gtk::MessageDialog dialog(_("Failed to save project file"), false, Gtk::MessageType::MESSAGE_ERROR, Gtk::ButtonsType::BUTTONS_OK, true);
            dialog.set_title(_("Project"));
            dialog.set_secondary_text(e.what());
            dialog.run();
        } catch (const Gio::Error &e) {
            Gtk::MessageDialog dialog(_("Failed to save project file"), false, Gtk::MessageType::MESSAGE_ERROR, Gtk::ButtonsType::BUTTONS_OK, true);
            dialog.set_title(_("Project"));
            dialog.set_secondary_text(e.what());
            dialog.run();
        }
    }

    void shader_pack_project::on_load() {
        save_project_file();
        file_tree = std::make_shared<project_file_tree>(root);
        file_tree->reload();
    }

    std::shared_ptr<project_file_tree> shader_pack_project::get_file_tree() {
        return file_tree;
    }
}