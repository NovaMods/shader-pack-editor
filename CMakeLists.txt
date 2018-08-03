cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

project(nova-shader-editor)

function(po_to_mo LANGUAGE)
    add_custom_command (
            TARGET nova-shader-editor-resources-gen
            PRE_BUILD
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources/schemas
            COMMAND msgfmt --output-file=${LANGUAGE}/editor.mo ${LANGUAGE}/editor.po
    )
endfunction()

link_directories(${GTKMM_LIBRARY_DIRS})

set(THIRD_PARTY_INCLUDE_DIRS
        3rdparty/json/include)

include_directories(${GTKMM_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(RESOURCE_GEN_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.c
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.h)

set(NOVA_SHADER_EDITOR_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/window/launcher_window.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/window/launcher_window.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/application/application.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/application/application.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/project/shader_pack_project.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/project/shader_pack_project.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/util/result.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/util/util.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/util/stream_utils.hpp
        ${CMAKE_CURRENT_LIST_DIR}/src/window/glade_window.hpp src/util/file_utils.hpp)

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
target_link_libraries(nova-shader-editor ${GTKMM_LIBRARIES})
