cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

project(NovaShaderEditorGtk)
link_directories(${GTKMM_LIBRARY_DIRS})

set(THIRD_PARTY_INCLUDE_DIRS
        3rdparty/json/include
        )

include_directories(${GTKMM_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_custom_command (
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/resources/resources.c
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.c --c-name=nova --generate gresource.xml
)

add_custom_command (
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/resources/resources.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/resources
        COMMAND glib-compile-resources --target=resources.h --c-name=nova --generate gresource.xml
)

add_executable(NovaShaderEditorGtk resources/resources.c resources/resources.h src/main.cpp src/window/launcher_window.cpp src/window/launcher_window.hpp src/application/application.cpp src/application/application.hpp src/project/shader_pack_project.cpp src/project/shader_pack_project.hpp src/util/result.hpp src/util/util.hpp)
target_link_libraries(NovaShaderEditorGtk ${GTKMM_LIBRARIES})