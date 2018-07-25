cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

project(NovaShaderEditorGtk)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(NovaShaderEditorGtk src/main.cpp src/window/launcher_window.cpp src/window/launcher_window.hpp src/application/application.cpp src/application/application.hpp src/project/shader_pack_project.cpp src/project/shader_pack_project.hpp)
target_link_libraries(NovaShaderEditorGtk ${GTKMM_LIBRARIES})