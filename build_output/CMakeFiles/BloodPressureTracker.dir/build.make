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
CMAKE_BINARY_DIR = /mnt/c/git/BloodPressureTracker/build_output

# Include any dependencies generated for this target.
include CMakeFiles/BloodPressureTracker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BloodPressureTracker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BloodPressureTracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BloodPressureTracker.dir/flags.make

CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o: CMakeFiles/BloodPressureTracker.dir/flags.make
CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o: /mnt/c/git/BloodPressureTracker/src/databaseController.cpp
CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o: CMakeFiles/BloodPressureTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/git/BloodPressureTracker/build_output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o -MF CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o.d -o CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o -c /mnt/c/git/BloodPressureTracker/src/databaseController.cpp

CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/git/BloodPressureTracker/src/databaseController.cpp > CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.i

CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/git/BloodPressureTracker/src/databaseController.cpp -o CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.s

CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o: CMakeFiles/BloodPressureTracker.dir/flags.make
CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o: /mnt/c/git/BloodPressureTracker/src/tcpSocket.cpp
CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o: CMakeFiles/BloodPressureTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/git/BloodPressureTracker/build_output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o -MF CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o.d -o CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o -c /mnt/c/git/BloodPressureTracker/src/tcpSocket.cpp

CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/git/BloodPressureTracker/src/tcpSocket.cpp > CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.i

CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/git/BloodPressureTracker/src/tcpSocket.cpp -o CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.s

CMakeFiles/BloodPressureTracker.dir/main.cpp.o: CMakeFiles/BloodPressureTracker.dir/flags.make
CMakeFiles/BloodPressureTracker.dir/main.cpp.o: /mnt/c/git/BloodPressureTracker/src/main.cpp
CMakeFiles/BloodPressureTracker.dir/main.cpp.o: CMakeFiles/BloodPressureTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/git/BloodPressureTracker/build_output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BloodPressureTracker.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BloodPressureTracker.dir/main.cpp.o -MF CMakeFiles/BloodPressureTracker.dir/main.cpp.o.d -o CMakeFiles/BloodPressureTracker.dir/main.cpp.o -c /mnt/c/git/BloodPressureTracker/src/main.cpp

CMakeFiles/BloodPressureTracker.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BloodPressureTracker.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/git/BloodPressureTracker/src/main.cpp > CMakeFiles/BloodPressureTracker.dir/main.cpp.i

CMakeFiles/BloodPressureTracker.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BloodPressureTracker.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/git/BloodPressureTracker/src/main.cpp -o CMakeFiles/BloodPressureTracker.dir/main.cpp.s

# Object files for target BloodPressureTracker
BloodPressureTracker_OBJECTS = \
"CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o" \
"CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o" \
"CMakeFiles/BloodPressureTracker.dir/main.cpp.o"

# External object files for target BloodPressureTracker
BloodPressureTracker_EXTERNAL_OBJECTS =

BloodPressureTracker: CMakeFiles/BloodPressureTracker.dir/databaseController.cpp.o
BloodPressureTracker: CMakeFiles/BloodPressureTracker.dir/tcpSocket.cpp.o
BloodPressureTracker: CMakeFiles/BloodPressureTracker.dir/main.cpp.o
BloodPressureTracker: CMakeFiles/BloodPressureTracker.dir/build.make
BloodPressureTracker: /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so
BloodPressureTracker: CMakeFiles/BloodPressureTracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/git/BloodPressureTracker/build_output/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BloodPressureTracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BloodPressureTracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BloodPressureTracker.dir/build: BloodPressureTracker
.PHONY : CMakeFiles/BloodPressureTracker.dir/build

CMakeFiles/BloodPressureTracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BloodPressureTracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BloodPressureTracker.dir/clean

CMakeFiles/BloodPressureTracker.dir/depend:
	cd /mnt/c/git/BloodPressureTracker/build_output && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/git/BloodPressureTracker/src /mnt/c/git/BloodPressureTracker/src /mnt/c/git/BloodPressureTracker/build_output /mnt/c/git/BloodPressureTracker/build_output /mnt/c/git/BloodPressureTracker/build_output/CMakeFiles/BloodPressureTracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BloodPressureTracker.dir/depend

