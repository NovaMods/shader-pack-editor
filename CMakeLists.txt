cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

project(nova-shader-editor)
link_directories(${GTKMM_LIBRARY_DIRS})

set(THIRD_PARTY_INCLUDE_DIRS
        3rdparty/json/include)

include_directories(${GTKMM_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(RESOURCE_GEN_SOURCE
        resources/resources.c
        resources/resources.h)

set(NOVA_SHADER_EDITOR_SOURCE
        src/main.cpp
        src/window/launcher_window.cpp
        src/window/launcher_window.hpp
        src/application/application.cpp
        src/application/application.hpp
        src/project/shader_pack_project.cpp
        src/project/shader_pack_project.hpp
        src/util/result.hpp
        src/util/util.hpp src/util/stream_utils.hpp)

add_executable(nova-shader-editor ${NOVA_SHADER_EDITOR_SOURCE} ${RESOURCE_GEN_SOURCE})

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/resources/schemas/gschemas.compiled
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources/schemas
        COMMAND glib-compile-schemas .
)

add_custom_command (
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/resources/resources.c
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.c --c-name=nova --generate gresource.xml)

add_custom_command (
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/resources/resources.h
        PRE_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.h --c-name=nova --generate gresource.xml)

add_custom_target(nova-shader-editor-resources-gen DEPENDS
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.h
        ${CMAKE_CURRENT_LIST_DIR}/resources/resources.c
        ${CMAKE_CURRENT_LIST_DIR}/resources/schemas/gschemas.compiled)

add_dependencies(nova-shader-editor nova-shader-editor-resources-gen)
target_link_libraries(nova-shader-editor ${GTKMM_LIBRARIES})