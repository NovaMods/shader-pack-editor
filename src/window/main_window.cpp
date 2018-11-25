//
// Created by jannis on 04.08.18.
//

#include "main_window.hpp"
#include "../application/application.hpp"
#include "../editors/generic_file_editor.hpp"

#ifdef GTK_SOURCE_H_INSIDE
#   undef GTK_SOURCE_H_INSIDE
#endif
#include <gtksourceview/gtksource.h>

namespace shader_editor {
    main_window::main_window() : glade_window("/com/continuum/shaderpackeditor/ui/main_ui.glade") {
        setup();
    }

    void main_window::setup() {
        get_widget("window", window);
        get_widget("editor_notebook", editor_notebook);

        Gtk::Button *style_chooser_button = Gtk::manage(Glib::wrap(GTK_BUTTON(gtk_source_style_scheme_chooser_button_new())));
        style_chooser_button->show_all();
        get_widget<Gtk::HeaderBar>("headerbar")->pack_end(*style_chooser_button);
        application::instance->set_source_style_scheme(gtk_source_style_scheme_chooser_get_style_scheme(GTK_SOURCE_STYLE_SCHEME_CHOOSER(style_chooser_button->gobj())));
        style_chooser_button->connect_property_changed("style-scheme", [style_chooser_button]{
            application::instance->set_source_style_scheme(gtk_source_style_scheme_chooser_get_style_scheme(GTK_SOURCE_STYLE_SCHEME_CHOOSER(style_chooser_button->gobj())));
        });
    }

    Gtk::Window *main_window::get_window() {
        return window.get();
    }

    void main_window::project_loaded() {
        application::instance->get_current_project()->get_file_tree()->setup_treeview(get_widget<Gtk::TreeView>("project_file_treeview"));

        auto editor = std::make_shared<generic_file_editor>(Gio::File::create_for_path(application::instance->get_current_project()->root + "/project.json"));
        set_tab("test", editor);
    }

    bool main_window::has_tab(const Glib::ustring &uuid) {
        return editors.find(uuid) != editors.end();
    }

    void main_window::set_tab(const Glib::ustring &uuid, std::shared_ptr<abstract_editor> editor) {
        if(has_tab(uuid)) {
            auto old_editor = editors.at(uuid).first;
            old_editor->signal_title_changed().clear();

            Gtk::ScrolledWindow *content_view = editors.at(uuid).second;
            content_view->Container::remove(*old_editor->get_view());
            editors.erase(uuid);
            content_view->add(*editor->get_view());

            auto *close_button = dynamic_cast<Gtk::Button *>(editor_notebook->get_tab_label(*content_view));
            editor->signal_title_changed().connect([close_button](Glib::ustring new_title){
                close_button->set_label(new_title);
            });
            editors.insert(std::make_pair(uuid, std::make_pair(editor, content_view)));
        } else {
            Gtk::HBox *tab_label_box = Gtk::manage(new Gtk::HBox());

            Gtk::Label *tab_label = Gtk::manage(new Gtk::Label());
            tab_label->set_text(editor->get_title());
            editor->signal_title_changed().connect([tab_label](Glib::ustring new_title){
                tab_label->set_text(new_title);
            });
            tab_label_box->pack_start(*tab_label);

            Gtk::Button *close_button = Gtk::manage(new Gtk::Button());
            close_button->set_relief(Gtk::ReliefStyle::RELIEF_NONE);
            close_button->set_image_from_icon_name("window-close-symbolic");
            close_button->signal_clicked().connect([this, uuid]{
                close_tab(uuid);
            });
            tab_label_box->pack_start(*close_button);

            tab_label_box->show_all();

            auto *content_view = new Gtk::ScrolledWindow();
            content_view->add(*editor->get_view());
            editor_notebook->append_page(*content_view, *tab_label_box);
            editors.insert(std::make_pair(uuid, std::make_pair(editor, content_view)));
            editor_notebook->show_all();
        }
    }

    bool main_window::close_tab(const Glib::ustring &uuid) {
        if(!has_tab(uuid)) {
            return false;
        }

        auto old_editor = editors.at(uuid).first;
        Gtk::ScrolledWindow *content_view = editors.at(uuid).second;
        content_view->Container::remove(*old_editor->get_view());
        editors.erase(uuid);

        delete content_view;
        return true;
    }

}