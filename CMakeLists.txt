cmake_minimum_required(VERSION 3.5.2)

project(nova-shader-editor)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
pkg_check_modules(GTKSOURCEVIEW gtksourceview-4 REQUIRED)

function(po_to_mo LANGUAGE)
    add_custom_command (
            TARGET nova-shader-editor-resources-gen
            PRE_BUILD
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources/schemas
            COMMAND msgfmt --output-file=${LANGUAGE}/editor.mo ${LANGUAGE}/editor.po
    )
endfunction()

link_directories(${GTKMM_LIBRARY_DIRS} ${GTKSOURCEVIEW_LIBRARY_DIRS})

set(THIRD_PARTY_INCLUDE_DIRS
        3rdparty/json/include)

include_directories(${GTKMM_INCLUDE_DIRS} ${GTKSOURCEVIEW_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(RESOURCE_GEN_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.c
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.h)

set(NOVA_SHADER_EDITOR_SOURCE
        src/main.cpp
        src/window/launcher_window.cpp
        src/window/launcher_window.hpp
        src/application/application.cpp
        src/application/application.hpp
        src/project/shader_pack_project.cpp
        src/project/shader_pack_project.hpp
        src/util/result.hpp
        src/util/util.hpp
        src/util/stream_utils.hpp
        src/window/glade_window.hpp src/util/file_utils.hpp src/window/main_window.cpp src/window/main_window.hpp src/project/project_file_tree.cpp src/project/project_file_tree.hpp src/editors/generic_file_editor.cpp src/editors/generic_file_editor.hpp src/editors/abstract_editor.hpp)

add_executable(nova-shader-editor ${NOVA_SHADER_EDITOR_SOURCE} ${RESOURCE_GEN_SOURCE})

add_custom_target(nova-shader-editor-resources-gen ALL)

add_custom_command (
        TARGET nova-shader-editor-resources-gen
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources/schemas
        COMMAND glib-compile-schemas .
)

add_custom_command (
        DEPENDS resources/gresource.xml
        TARGET nova-shader-editor-resources-gen
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.c --c-name=nova --generate gresource.xml)

add_custom_command (
        TARGET nova-shader-editor-resources-gen
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.h --c-name=nova --generate gresource.xml)

add_dependencies(nova-shader-editor nova-shader-editor-resources-gen)
target_link_libraries(nova-shader-editor ${GTKMM_LIBRARIES} ${GTKSOURCEVIEW_LIBRARIES})
target_compile_definitions(nova-shader-editor PRIVATE GTKMM_DISABLE_DEPRECATED=1)
