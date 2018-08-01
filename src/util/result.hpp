//
// Created by jannis on 25.07.18.
//

#ifndef NOVASHADEREDITORGTK_RESULT_HPP
#define NOVASHADEREDITORGTK_RESULT_HPP

#include <optional>
#include <utility>

namespace shader_editor {
    template <typename T>
    class optional_result {
    public:
        std::optional<T> opt;
        Glib::ustring err_message;

        explicit optional_result(Glib::ustring err_message) : err_message(err_message), opt(std::nullopt) {}
        explicit optional_result(T obj): opt(std::optional<T>(obj)) {}

        explicit operator bool() {
            return !!opt;
        }
    };

    template <typename T>
    class type_result {
    private:
        bool ok;
        type_result() : ok(false) {};

    public:
        T obj;
        Glib::ustring err_message{};

        explicit type_result(Glib::ustring err_message) : err_message(err_message), ok(false) {}
        explicit type_result(T obj) : obj(obj), ok(true) {}

        explicit operator bool() {
            return ok;
        }
    };
}

#endif //NOVASHADEREDITORGTK_RESULT_HPP
