//
// Created by jannis on 25.07.18.
//

#include <giomm/file.h>
#include "shader_pack_project.hpp"

namespace shader_editor {
    std::shared_ptr<shader_pack_project> shader_pack_project::from_file(Glib::ustring file_path) {
        auto file = Gio::File::create_for_path(file_path);
        auto project = from_scratch();
    }

    std::shared_ptr<shader_pack_project> shader_pack_project::from_scratch() {
        return std::make_shared<shader_pack_project>();
    }

    shader_pack_project::shader_pack_project() {

    }
}