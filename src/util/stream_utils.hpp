//
// Created by jannis on 26.07.18.
//

#ifndef NOVA_SHADER_EDITOR_STREAM_UTILS_HPP
#define NOVA_SHADER_EDITOR_STREAM_UTILS_HPP

#include <giomm/inputstream.h>
#include <giomm/outputstream.h>
#include <utility>

namespace shader_editor {
    class stream_utils {
    public:
        static void copy(const Glib::RefPtr<Gio::InputStream> &in, const Glib::RefPtr<Gio::OutputStream> &out) {
            char buffer[4096];
            gssize read_bytes;
            while((read_bytes = in->read(buffer, 4096)) > 0) {
                gssize wrote_bytes;
                if((wrote_bytes = out->write(buffer, static_cast<gsize>(read_bytes))) != read_bytes) {
                    throw copy_exception(Glib::ustring::compose("Expected to copy %1 bytes, but copied %2 bytes", read_bytes, wrote_bytes));
                }
            }
        }

        class copy_exception : public std::exception {
        private:
            Glib::ustring msg;

        public:
            copy_exception(Glib::ustring msg) : msg(std::move(msg)) {}

            const char *what() const noexcept override {
                return msg.c_str();
            }
        };
    };
}

#endif //NOVA_SHADER_EDITOR_STREAM_UTILS_HPP
