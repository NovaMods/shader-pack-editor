# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/jannis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5540.8/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jannis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5540.8/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NovaShaderEditorGtk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NovaShaderEditorGtk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NovaShaderEditorGtk.dir/flags.make

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o: CMakeFiles/NovaShaderEditorGtk.dir/flags.make
CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o -c /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/main.cpp

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/main.cpp > CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.i

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/main.cpp -o CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.s

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.requires

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.provides: CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NovaShaderEditorGtk.dir/build.make CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.provides

CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.provides.build: CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o


CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o: CMakeFiles/NovaShaderEditorGtk.dir/flags.make
CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o: ../src/window/launcher_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o -c /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/window/launcher_window.cpp

CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/window/launcher_window.cpp > CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.i

CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/window/launcher_window.cpp -o CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.s

CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.requires:

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.requires

CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.provides: CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.requires
	$(MAKE) -f CMakeFiles/NovaShaderEditorGtk.dir/build.make CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.provides.build
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.provides

CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.provides.build: CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o


CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o: CMakeFiles/NovaShaderEditorGtk.dir/flags.make
CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o: ../src/application/application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o -c /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/application/application.cpp

CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/application/application.cpp > CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.i

CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/application/application.cpp -o CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.s

CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.requires:

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.requires

CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.provides: CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.requires
	$(MAKE) -f CMakeFiles/NovaShaderEditorGtk.dir/build.make CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.provides.build
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.provides

CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.provides.build: CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o


CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o: CMakeFiles/NovaShaderEditorGtk.dir/flags.make
CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o: ../src/project/shader_pack_project.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o -c /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/project/shader_pack_project.cpp

CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/project/shader_pack_project.cpp > CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.i

CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/src/project/shader_pack_project.cpp -o CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.s

CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.requires:

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.requires

CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.provides: CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.requires
	$(MAKE) -f CMakeFiles/NovaShaderEditorGtk.dir/build.make CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.provides.build
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.provides

CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.provides.build: CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o


# Object files for target NovaShaderEditorGtk
NovaShaderEditorGtk_OBJECTS = \
"CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o" \
"CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o" \
"CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o" \
"CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o"

# External object files for target NovaShaderEditorGtk
NovaShaderEditorGtk_EXTERNAL_OBJECTS =

NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o
NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o
NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o
NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o
NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/build.make
NovaShaderEditorGtk: CMakeFiles/NovaShaderEditorGtk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable NovaShaderEditorGtk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NovaShaderEditorGtk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NovaShaderEditorGtk.dir/build: NovaShaderEditorGtk

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/build

CMakeFiles/NovaShaderEditorGtk.dir/requires: CMakeFiles/NovaShaderEditorGtk.dir/src/main.cpp.o.requires
CMakeFiles/NovaShaderEditorGtk.dir/requires: CMakeFiles/NovaShaderEditorGtk.dir/src/window/launcher_window.cpp.o.requires
CMakeFiles/NovaShaderEditorGtk.dir/requires: CMakeFiles/NovaShaderEditorGtk.dir/src/application/application.cpp.o.requires
CMakeFiles/NovaShaderEditorGtk.dir/requires: CMakeFiles/NovaShaderEditorGtk.dir/src/project/shader_pack_project.cpp.o.requires

.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/requires

CMakeFiles/NovaShaderEditorGtk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NovaShaderEditorGtk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/clean

CMakeFiles/NovaShaderEditorGtk.dir/depend:
	cd /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug /home/jannis/Dokumente/Coding/Native/NovaShaderEditorGtk/cmake-build-debug/CMakeFiles/NovaShaderEditorGtk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NovaShaderEditorGtk.dir/depend
