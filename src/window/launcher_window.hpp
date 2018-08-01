//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP
#define NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP

#include <gtkmm.h>
#include "glade_window.hpp"

namespace shader_editor {
    class launcher_window : public glade_window {
    private:
        std::shared_ptr<Gtk::Window> window; // Store to auto delete it on deconstruction
        void setup();
        void open_clicked();

        bool name_ok = false;
        bool path_ok = false;

    public:
        launcher_window();
        Gtk::Window *get_window() override;
    };
}

#endif //NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP
