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
CMAKE_BINARY_DIR = /home/zihao/qedis/Qedis

# Include any dependencies generated for this target.
include courses/lab2/code2/CMakeFiles/server2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include courses/lab2/code2/CMakeFiles/server2.dir/compiler_depend.make

# Include the progress variables for this target.
include courses/lab2/code2/CMakeFiles/server2.dir/progress.make

# Include the compile flags for this target's objects.
include courses/lab2/code2/CMakeFiles/server2.dir/flags.make

courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o: courses/lab2/code2/CMakeFiles/server2.dir/flags.make
courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o: courses/lab2/code2/EchoSocket.cc
courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o: courses/lab2/code2/CMakeFiles/server2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zihao/qedis/Qedis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o -MF CMakeFiles/server2.dir/EchoSocket.cc.o.d -o CMakeFiles/server2.dir/EchoSocket.cc.o -c /home/zihao/qedis/Qedis/courses/lab2/code2/EchoSocket.cc

courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server2.dir/EchoSocket.cc.i"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zihao/qedis/Qedis/courses/lab2/code2/EchoSocket.cc > CMakeFiles/server2.dir/EchoSocket.cc.i

courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server2.dir/EchoSocket.cc.s"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zihao/qedis/Qedis/courses/lab2/code2/EchoSocket.cc -o CMakeFiles/server2.dir/EchoSocket.cc.s

courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o: courses/lab2/code2/CMakeFiles/server2.dir/flags.make
courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o: courses/lab2/code2/Server2.cc
courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o: courses/lab2/code2/CMakeFiles/server2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zihao/qedis/Qedis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o -MF CMakeFiles/server2.dir/Server2.cc.o.d -o CMakeFiles/server2.dir/Server2.cc.o -c /home/zihao/qedis/Qedis/courses/lab2/code2/Server2.cc

courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server2.dir/Server2.cc.i"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zihao/qedis/Qedis/courses/lab2/code2/Server2.cc > CMakeFiles/server2.dir/Server2.cc.i

courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server2.dir/Server2.cc.s"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zihao/qedis/Qedis/courses/lab2/code2/Server2.cc -o CMakeFiles/server2.dir/Server2.cc.s

# Object files for target server2
server2_OBJECTS = \
"CMakeFiles/server2.dir/EchoSocket.cc.o" \
"CMakeFiles/server2.dir/Server2.cc.o"

# External object files for target server2
server2_EXTERNAL_OBJECTS =

courses/lab2/code2/server2: courses/lab2/code2/CMakeFiles/server2.dir/EchoSocket.cc.o
courses/lab2/code2/server2: courses/lab2/code2/CMakeFiles/server2.dir/Server2.cc.o
courses/lab2/code2/server2: courses/lab2/code2/CMakeFiles/server2.dir/build.make
courses/lab2/code2/server2: /home/zihao/qedis/bin/libqbaselib.a
courses/lab2/code2/server2: courses/lab2/code2/CMakeFiles/server2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zihao/qedis/Qedis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable server2"
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
courses/lab2/code2/CMakeFiles/server2.dir/build: courses/lab2/code2/server2
.PHONY : courses/lab2/code2/CMakeFiles/server2.dir/build

courses/lab2/code2/CMakeFiles/server2.dir/clean:
	cd /home/zihao/qedis/Qedis/courses/lab2/code2 && $(CMAKE_COMMAND) -P CMakeFiles/server2.dir/cmake_clean.cmake
.PHONY : courses/lab2/code2/CMakeFiles/server2.dir/clean

courses/lab2/code2/CMakeFiles/server2.dir/depend:
	cd /home/zihao/qedis/Qedis && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zihao/qedis/Qedis /home/zihao/qedis/Qedis/courses/lab2/code2 /home/zihao/qedis/Qedis /home/zihao/qedis/Qedis/courses/lab2/code2 /home/zihao/qedis/Qedis/courses/lab2/code2/CMakeFiles/server2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : courses/lab2/code2/CMakeFiles/server2.dir/depend
