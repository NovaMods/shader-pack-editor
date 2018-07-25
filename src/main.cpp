//
// Created by jannis on 25.07.18.
//

#include <gtkmm.h>
#include "application/application.hpp"

int main(int argc, char **argv)
{
    shader_editor::application::create(argc, argv);
    return shader_editor::application::instance->run();
}