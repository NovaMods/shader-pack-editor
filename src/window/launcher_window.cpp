//
// Created by jannis on 25.07.18.
//

#include <iostream>
#include "launcher_window.hpp"
#include "../project/shader_pack_project.hpp"

namespace shader_editor {
    launcher_window::launcher_window() : Gtk::Window(), open_project_btn("Open project") {
        set_default_size(800, 400);
        set_icon(icon);

        container.pack_end(logo);

        open_project_btn.signal_clicked().connect(sigc::mem_fun(this, &launcher_window::on_open_project_clicked));
        container.pack_end(open_project_btn);

        add(container);
    }

    void launcher_window::on_open_project_clicked() {
        Gtk::FileChooserDialog dialog("Open project", Gtk::FILE_CHOOSER_ACTION_OPEN);
        dialog.set_transient_for(*this);

        dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
        dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

        switch (dialog.run()) {
            case Gtk::RESPONSE_OK: {
                auto proj = shader_pack_project::from_file(dialog.get_filename());
                std::cout << proj.obj->name << std::endl;
                if (proj) {
                    std::cout << "Name: " << proj.obj->name;
                } else {
                    std::cerr << "ERR: " << proj.err_message;
                }
                break;
            }

            default:
                break;
        }
    }
}