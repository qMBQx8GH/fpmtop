# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/src/fpmtop/fpmtop/proj.cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/src/fpmtop/fpmtop/proj.cmake/build

# Include any dependencies generated for this target.
include pugixml/CMakeFiles/pugixml.dir/depend.make

# Include the progress variables for this target.
include pugixml/CMakeFiles/pugixml.dir/progress.make

# Include the compile flags for this target's objects.
include pugixml/CMakeFiles/pugixml.dir/flags.make

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o: pugixml/CMakeFiles/pugixml.dir/flags.make
pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o: /opt/src/fpmtop/pugixml/src/pugixml.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/src/fpmtop/fpmtop/proj.cmake/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o"
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pugixml.dir/src/pugixml.cpp.o -c /opt/src/fpmtop/pugixml/src/pugixml.cpp

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pugixml.dir/src/pugixml.cpp.i"
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/src/fpmtop/pugixml/src/pugixml.cpp > CMakeFiles/pugixml.dir/src/pugixml.cpp.i

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pugixml.dir/src/pugixml.cpp.s"
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/src/fpmtop/pugixml/src/pugixml.cpp -o CMakeFiles/pugixml.dir/src/pugixml.cpp.s

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.requires:
.PHONY : pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.requires

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.provides: pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.requires
	$(MAKE) -f pugixml/CMakeFiles/pugixml.dir/build.make pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.provides.build
.PHONY : pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.provides

pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.provides.build: pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o

# Object files for target pugixml
pugixml_OBJECTS = \
"CMakeFiles/pugixml.dir/src/pugixml.cpp.o"

# External object files for target pugixml
pugixml_EXTERNAL_OBJECTS =

pugixml/libpugixml.a: pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o
pugixml/libpugixml.a: pugixml/CMakeFiles/pugixml.dir/build.make
pugixml/libpugixml.a: pugixml/CMakeFiles/pugixml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libpugixml.a"
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean_target.cmake
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pugixml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pugixml/CMakeFiles/pugixml.dir/build: pugixml/libpugixml.a
.PHONY : pugixml/CMakeFiles/pugixml.dir/build

pugixml/CMakeFiles/pugixml.dir/requires: pugixml/CMakeFiles/pugixml.dir/src/pugixml.cpp.o.requires
.PHONY : pugixml/CMakeFiles/pugixml.dir/requires

pugixml/CMakeFiles/pugixml.dir/clean:
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/pugixml.dir/cmake_clean.cmake
.PHONY : pugixml/CMakeFiles/pugixml.dir/clean

pugixml/CMakeFiles/pugixml.dir/depend:
	cd /opt/src/fpmtop/fpmtop/proj.cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/src/fpmtop/fpmtop/proj.cmake /opt/src/fpmtop/pugixml /opt/src/fpmtop/fpmtop/proj.cmake/build /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml /opt/src/fpmtop/fpmtop/proj.cmake/build/pugixml/CMakeFiles/pugixml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pugixml/CMakeFiles/pugixml.dir/depend

