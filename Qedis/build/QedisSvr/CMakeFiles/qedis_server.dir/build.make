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
CMAKE_SOURCE_DIR = /home/zihao/qedis/Qedis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zihao/qedis/Qedis/build

# Include any dependencies generated for this target.
include QedisSvr/CMakeFiles/qedis_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include QedisSvr/CMakeFiles/qedis_server.dir/compiler_depend.make

# Include the progress variables for this target.
include QedisSvr/CMakeFiles/qedis_server.dir/progress.make

# Include the compile flags for this target's objects.
include QedisSvr/CMakeFiles/qedis_server.dir/flags.make

QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o: QedisSvr/CMakeFiles/qedis_server.dir/flags.make
QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o: ../QedisSvr/Qedis.cc
QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o: QedisSvr/CMakeFiles/qedis_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zihao/qedis/Qedis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o"
	cd /home/zihao/qedis/Qedis/build/QedisSvr && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o -MF CMakeFiles/qedis_server.dir/Qedis.cc.o.d -o CMakeFiles/qedis_server.dir/Qedis.cc.o -c /home/zihao/qedis/Qedis/QedisSvr/Qedis.cc

QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qedis_server.dir/Qedis.cc.i"
	cd /home/zihao/qedis/Qedis/build/QedisSvr && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zihao/qedis/Qedis/QedisSvr/Qedis.cc > CMakeFiles/qedis_server.dir/Qedis.cc.i

QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qedis_server.dir/Qedis.cc.s"
	cd /home/zihao/qedis/Qedis/build/QedisSvr && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zihao/qedis/Qedis/QedisSvr/Qedis.cc -o CMakeFiles/qedis_server.dir/Qedis.cc.s

# Object files for target qedis_server
qedis_server_OBJECTS = \
"CMakeFiles/qedis_server.dir/Qedis.cc.o"

# External object files for target qedis_server
qedis_server_EXTERNAL_OBJECTS =

../bin/qedis_server: QedisSvr/CMakeFiles/qedis_server.dir/Qedis.cc.o
../bin/qedis_server: QedisSvr/CMakeFiles/qedis_server.dir/build.make
../bin/qedis_server: ../bin/libqediscore.a
../bin/qedis_server: ../bin/libqbaselib.a
../bin/qedis_server: QedisSvr/CMakeFiles/qedis_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zihao/qedis/Qedis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/qedis_server"
	cd /home/zihao/qedis/Qedis/build/QedisSvr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qedis_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
QedisSvr/CMakeFiles/qedis_server.dir/build: ../bin/qedis_server
.PHONY : QedisSvr/CMakeFiles/qedis_server.dir/build

QedisSvr/CMakeFiles/qedis_server.dir/clean:
	cd /home/zihao/qedis/Qedis/build/QedisSvr && $(CMAKE_COMMAND) -P CMakeFiles/qedis_server.dir/cmake_clean.cmake
.PHONY : QedisSvr/CMakeFiles/qedis_server.dir/clean

QedisSvr/CMakeFiles/qedis_server.dir/depend:
	cd /home/zihao/qedis/Qedis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zihao/qedis/Qedis /home/zihao/qedis/Qedis/QedisSvr /home/zihao/qedis/Qedis/build /home/zihao/qedis/Qedis/build/QedisSvr /home/zihao/qedis/Qedis/build/QedisSvr/CMakeFiles/qedis_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : QedisSvr/CMakeFiles/qedis_server.dir/depend

