//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP
#define NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP

#include <memory>
#include <glibmm.h>
#include "../util/result.hpp"
#include "project_file_tree.hpp"

namespace shader_editor {
    class shader_pack_project {
    private:
        std::shared_ptr<project_file_tree> file_tree;

        shader_pack_project();

    public:
        static type_result<std::shared_ptr<shader_pack_project>> from_file(Glib::ustring file_path);
        static std::shared_ptr<shader_pack_project> from_scratch();

        Glib::ustring name;
        Glib::ustring root;

        ~shader_pack_project();

        void save_project_file();
        void on_load();
        std::shared_ptr<project_file_tree> get_file_tree();
    };
}


#endif //NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP
