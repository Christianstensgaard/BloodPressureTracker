# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/git/BloodPressureTracker/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/git/BloodPressureTracker/src/build

# Utility rule file for full_build.

# Include any custom commands dependencies for this target.
include CMakeFiles/full_build.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/full_build.dir/progress.make

CMakeFiles/full_build:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/git/BloodPressureTracker/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Full Build: Clean Docker, Build Image, Run Container"

full_build: CMakeFiles/full_build
full_build: CMakeFiles/full_build.dir/build.make
.PHONY : full_build

# Rule to build all files generated by this target.
CMakeFiles/full_build.dir/build: full_build
.PHONY : CMakeFiles/full_build.dir/build

CMakeFiles/full_build.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/full_build.dir/cmake_clean.cmake
.PHONY : CMakeFiles/full_build.dir/clean

CMakeFiles/full_build.dir/depend:
	cd /mnt/c/git/BloodPressureTracker/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/git/BloodPressureTracker/src /mnt/c/git/BloodPressureTracker/src /mnt/c/git/BloodPressureTracker/src/build /mnt/c/git/BloodPressureTracker/src/build /mnt/c/git/BloodPressureTracker/src/build/CMakeFiles/full_build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/full_build.dir/depend

