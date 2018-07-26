//
// Created by jannis on 25.07.18.
//

#include <gtkmm.h>
#include <memory>

#include "application/application.hpp"

std::shared_ptr<shader_editor::application> shader_editor::application::instance;

int main(int argc, char **argv)
{
    shader_editor::application::create(argc, argv);
    return shader_editor::application::instance->run();
}