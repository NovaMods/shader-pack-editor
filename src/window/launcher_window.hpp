//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP
#define NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP

#include <gtkmm.h>

namespace shader_editor {
    class launcher_window : public Gtk::Window {
    private:
        Glib::RefPtr<Gdk::Pixbuf> icon = Gdk::Pixbuf::create_from_resource("/com/continuum/shaderpackeditor/global/icon.png");
        Gtk::Image logo = Gtk::Image(icon);

        Gtk::VBox container;
        Gtk::Label program_name_label;

        Gtk::Button new_project_btn;
        void on_new_project_clicked();

        Gtk::Button open_project_btn;
        void on_open_project_clicked();

    public:
        launcher_window();
    };
}

#endif //NOVASHADEREDITORGTK_LAUNCHER_WINDOW_HPP
