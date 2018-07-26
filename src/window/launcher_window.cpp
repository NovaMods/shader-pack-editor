//
// Created by jannis on 25.07.18.
//

#include <iostream>
#include "launcher_window.hpp"
#include "../project/shader_pack_project.hpp"

namespace shader_editor {
    launcher_window::launcher_window() : Gtk::Window(), open_project_btn("Open project"), new_project_btn("New project") {
        set_resizable(false);
        set_icon(icon);
        set_title("Nova Shaderpack Editor");

        container.pack_start(logo);

        program_name_label.set_markup("<span font='20'>Nova Shaderpack Editor</span>");
        container.pack_start(program_name_label);

        new_project_btn.signal_clicked().connect(sigc::mem_fun(this, &launcher_window::on_new_project_clicked));
        container.pack_start(new_project_btn);

        open_project_btn.signal_clicked().connect(sigc::mem_fun(this, &launcher_window::on_open_project_clicked));
        container.pack_start(open_project_btn);

        add(container);
    }

    void launcher_window::on_open_project_clicked() {
        Gtk::FileChooserDialog dialog("Open project", Gtk::FILE_CHOOSER_ACTION_OPEN);
        dialog.set_transient_for(*this);

        dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
        dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

        switch (dialog.run()) {
            case Gtk::RESPONSE_OK: {
                dialog.hide();
                auto proj = shader_pack_project::from_file(dialog.get_filename());
                if (proj) {
                    std::cout << "Name: " << proj.obj->name;
                } else {
                    Gtk::MessageDialog error_dialog(Glib::ustring::compose("Failed to open project file %1:", dialog.get_filename()),
                                                    false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
                    error_dialog.set_transient_for(*this);
                    error_dialog.set_secondary_text(proj.err_message);
                    error_dialog.set_title("Open project");
                    error_dialog.run();
                }
                break;
            }

            default:
                dialog.hide();
                break;
        }
    }

    void launcher_window::on_new_project_clicked() {

    }
}