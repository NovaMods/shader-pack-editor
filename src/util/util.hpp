//
// Created by jannis on 26.07.18.
//

#ifndef NOVASHADEREDITORGTK_JSON_ASSIGN_HPP
#define NOVASHADEREDITORGTK_JSON_ASSIGN_HPP

#include <nlohmann/json.hpp>
#include <exception>
#include <glibmm.h>

namespace shader_editor {
    class util {
    public:
        static void assign_from_json(const nlohmann::json &json, const Glib::ustring &key, int &val) {
            nlohmann::json jv;
            if(json.find(key) == json.end()) {
                throw missing_value_exception(key);
            }

            jv = json[key];
            if(!jv.is_number_integer()) {
                throw type_mismatch_exception("int", json.type_name());
            } else {
                val = jv.get<int>();
            }
        }

        static void assign_from_json(const nlohmann::json &json, const Glib::ustring &key, float &val) {
            nlohmann::json jv;
            if(json.find(key) == json.end()) {
                throw missing_value_exception(key);
            }

            jv = json[key];
            if(!jv.is_number_integer()) {
                throw type_mismatch_exception("float", json.type_name());
            } else {
                val = jv.get<float>();
            }
        }

        static void assign_from_json(const nlohmann::json &json, const Glib::ustring &key, Glib::ustring &val) {
            nlohmann::json jv;
            if(json.find(key) == json.end()) {
                throw missing_value_exception(key);
            }

            jv = json[key];
            if(!jv.is_string()) {
                throw type_mismatch_exception("string", json.type_name());
            } else {
                val = Glib::ustring(jv.get<std::string>());
            }
        }

        static void assign_from_json(const nlohmann::json &json, const Glib::ustring &key, bool &val) {
            nlohmann::json jv;
            if(json.find(key) == json.end()) {
                throw missing_value_exception(key);
            }

            jv = json[key];
            if(!jv.is_number_integer()) {
                throw type_mismatch_exception("bool", json.type_name());
            } else {
                val = jv.get<bool>();
            }
        }

        static void assign_from_json(const nlohmann::json &json, nlohmann::json &val) {
            if(!json.is_object()) {
                throw type_mismatch_exception("nlohman::json", json.type_name());
            } else {
                val = json;
            }
        }

        template <typename T>
        static void assign_from_json(const nlohmann::json &json, const Glib::ustring &key, std::vector<T> &val) {
            nlohmann::json jv;
            if(json.find(key) == json.end()) {
                throw missing_value_exception(key);
            }

            jv = json[key];
            if(!jv.is_number_integer()) {
                throw type_mismatch_exception(Glib::ustring::compose("std::vector<%1>", typeid(T).name()), json.type_name());
            } else {
                val = jv.get<std::vector<T>>();
            }
        }

        class type_mismatch_exception: public std::exception {
        private:
            Glib::ustring expected;
            Glib::ustring real;

        public:
            type_mismatch_exception(Glib::ustring expected, Glib::ustring real): expected(expected), real(real) {}

            const char *what() const noexcept override {
                return Glib::ustring::compose("Expected type %1, but got %2", expected, real).c_str();
            }
        };

        class missing_value_exception : public std::exception {
        private:
            Glib::ustring key;

        public:
            missing_value_exception(Glib::ustring key) : key(std::move(key)) {}

            const char *what() const noexcept override {
                return Glib::ustring::compose("Entry with key %1 not found", key).c_str();
            }
        };
    };
}

#endif //NOVASHADEREDITORGTK_JSON_ASSIGN_HPP
