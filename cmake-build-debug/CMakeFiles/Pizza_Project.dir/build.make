# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ianm/Desktop/Pizza_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ianm/Desktop/Pizza_Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pizza_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pizza_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pizza_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pizza_Project.dir/flags.make

CMakeFiles/Pizza_Project.dir/main.cpp.o: CMakeFiles/Pizza_Project.dir/flags.make
CMakeFiles/Pizza_Project.dir/main.cpp.o: ../main.cpp
CMakeFiles/Pizza_Project.dir/main.cpp.o: CMakeFiles/Pizza_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ianm/Desktop/Pizza_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pizza_Project.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pizza_Project.dir/main.cpp.o -MF CMakeFiles/Pizza_Project.dir/main.cpp.o.d -o CMakeFiles/Pizza_Project.dir/main.cpp.o -c /Users/ianm/Desktop/Pizza_Project/main.cpp

CMakeFiles/Pizza_Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pizza_Project.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ianm/Desktop/Pizza_Project/main.cpp > CMakeFiles/Pizza_Project.dir/main.cpp.i

CMakeFiles/Pizza_Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pizza_Project.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ianm/Desktop/Pizza_Project/main.cpp -o CMakeFiles/Pizza_Project.dir/main.cpp.s

# Object files for target Pizza_Project
Pizza_Project_OBJECTS = \
"CMakeFiles/Pizza_Project.dir/main.cpp.o"

# External object files for target Pizza_Project
Pizza_Project_EXTERNAL_OBJECTS =

Pizza_Project: CMakeFiles/Pizza_Project.dir/main.cpp.o
Pizza_Project: CMakeFiles/Pizza_Project.dir/build.make
Pizza_Project: CMakeFiles/Pizza_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ianm/Desktop/Pizza_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pizza_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pizza_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pizza_Project.dir/build: Pizza_Project
.PHONY : CMakeFiles/Pizza_Project.dir/build

CMakeFiles/Pizza_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pizza_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pizza_Project.dir/clean

CMakeFiles/Pizza_Project.dir/depend:
	cd /Users/ianm/Desktop/Pizza_Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ianm/Desktop/Pizza_Project /Users/ianm/Desktop/Pizza_Project /Users/ianm/Desktop/Pizza_Project/cmake-build-debug /Users/ianm/Desktop/Pizza_Project/cmake-build-debug /Users/ianm/Desktop/Pizza_Project/cmake-build-debug/CMakeFiles/Pizza_Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pizza_Project.dir/depend

