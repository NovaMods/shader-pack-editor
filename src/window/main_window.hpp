//
// Created by jannis on 04.08.18.
//

#ifndef NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP
#define NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP

#include "glade_window.hpp"

namespace shader_editor {
    class main_window : public glade_window {
    private:
        std::shared_ptr<Gtk::Window> window;
        void setup();

    public:
        explicit main_window();

        Gtk::Window *get_window() override;
    };
}


#endif //NOVA_SHADER_EDITOR_MAIN_WINDOW_HPP
