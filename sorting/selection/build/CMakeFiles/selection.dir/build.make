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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build

# Include any dependencies generated for this target.
include CMakeFiles/selection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/selection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/selection.dir/flags.make

CMakeFiles/selection.dir/selection.cpp.o: CMakeFiles/selection.dir/flags.make
CMakeFiles/selection.dir/selection.cpp.o: ../selection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/selection.dir/selection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/selection.dir/selection.cpp.o -c /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/selection.cpp

CMakeFiles/selection.dir/selection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/selection.dir/selection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/selection.cpp > CMakeFiles/selection.dir/selection.cpp.i

CMakeFiles/selection.dir/selection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/selection.dir/selection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/selection.cpp -o CMakeFiles/selection.dir/selection.cpp.s

CMakeFiles/selection.dir/selection.cpp.o.requires:

.PHONY : CMakeFiles/selection.dir/selection.cpp.o.requires

CMakeFiles/selection.dir/selection.cpp.o.provides: CMakeFiles/selection.dir/selection.cpp.o.requires
	$(MAKE) -f CMakeFiles/selection.dir/build.make CMakeFiles/selection.dir/selection.cpp.o.provides.build
.PHONY : CMakeFiles/selection.dir/selection.cpp.o.provides

CMakeFiles/selection.dir/selection.cpp.o.provides.build: CMakeFiles/selection.dir/selection.cpp.o


# Object files for target selection
selection_OBJECTS = \
"CMakeFiles/selection.dir/selection.cpp.o"

# External object files for target selection
selection_EXTERNAL_OBJECTS =

selection: CMakeFiles/selection.dir/selection.cpp.o
selection: CMakeFiles/selection.dir/build.make
selection: CMakeFiles/selection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable selection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/selection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/selection.dir/build: selection

.PHONY : CMakeFiles/selection.dir/build

CMakeFiles/selection.dir/requires: CMakeFiles/selection.dir/selection.cpp.o.requires

.PHONY : CMakeFiles/selection.dir/requires

CMakeFiles/selection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/selection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/selection.dir/clean

CMakeFiles/selection.dir/depend:
	cd /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build /mnt/c/Git/MyGitRepo/ds-algo-cpp/sorting/selection/build/CMakeFiles/selection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/selection.dir/depend
