//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP
#define NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP

#include <memory>
#include <glibmm.h>

namespace shader_editor {
    class shader_pack_project {
    public:
        static std::shared_ptr<shader_pack_project> from_file(Glib::ustring file_path);
        static std::shared_ptr<shader_pack_project> from_scratch();

    private:
        Glib::ustring name;
        shader_pack_project();
    };
}


#endif //NOVASHADEREDITORGTK_SHADER_PACK_PROJECT_HPP
