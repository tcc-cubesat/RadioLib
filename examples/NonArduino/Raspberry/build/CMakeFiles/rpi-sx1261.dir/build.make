# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/tccsat/RadioLib/examples/NonArduino/Raspberry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tccsat/RadioLib/examples/NonArduino/Raspberry/build

# Include any dependencies generated for this target.
include CMakeFiles/rpi-sx1261.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rpi-sx1261.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rpi-sx1261.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rpi-sx1261.dir/flags.make

CMakeFiles/rpi-sx1261.dir/main.cpp.o: CMakeFiles/rpi-sx1261.dir/flags.make
CMakeFiles/rpi-sx1261.dir/main.cpp.o: /home/tccsat/RadioLib/examples/NonArduino/Raspberry/main.cpp
CMakeFiles/rpi-sx1261.dir/main.cpp.o: CMakeFiles/rpi-sx1261.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tccsat/RadioLib/examples/NonArduino/Raspberry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rpi-sx1261.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rpi-sx1261.dir/main.cpp.o -MF CMakeFiles/rpi-sx1261.dir/main.cpp.o.d -o CMakeFiles/rpi-sx1261.dir/main.cpp.o -c /home/tccsat/RadioLib/examples/NonArduino/Raspberry/main.cpp

CMakeFiles/rpi-sx1261.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpi-sx1261.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tccsat/RadioLib/examples/NonArduino/Raspberry/main.cpp > CMakeFiles/rpi-sx1261.dir/main.cpp.i

CMakeFiles/rpi-sx1261.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpi-sx1261.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tccsat/RadioLib/examples/NonArduino/Raspberry/main.cpp -o CMakeFiles/rpi-sx1261.dir/main.cpp.s

# Object files for target rpi-sx1261
rpi__sx1261_OBJECTS = \
"CMakeFiles/rpi-sx1261.dir/main.cpp.o"

# External object files for target rpi-sx1261
rpi__sx1261_EXTERNAL_OBJECTS =

rpi-sx1261: CMakeFiles/rpi-sx1261.dir/main.cpp.o
rpi-sx1261: CMakeFiles/rpi-sx1261.dir/build.make
rpi-sx1261: RadioLib/libRadioLib.a
rpi-sx1261: CMakeFiles/rpi-sx1261.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tccsat/RadioLib/examples/NonArduino/Raspberry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rpi-sx1261"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpi-sx1261.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rpi-sx1261.dir/build: rpi-sx1261
.PHONY : CMakeFiles/rpi-sx1261.dir/build

CMakeFiles/rpi-sx1261.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rpi-sx1261.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rpi-sx1261.dir/clean

CMakeFiles/rpi-sx1261.dir/depend:
	cd /home/tccsat/RadioLib/examples/NonArduino/Raspberry/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tccsat/RadioLib/examples/NonArduino/Raspberry /home/tccsat/RadioLib/examples/NonArduino/Raspberry /home/tccsat/RadioLib/examples/NonArduino/Raspberry/build /home/tccsat/RadioLib/examples/NonArduino/Raspberry/build /home/tccsat/RadioLib/examples/NonArduino/Raspberry/build/CMakeFiles/rpi-sx1261.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rpi-sx1261.dir/depend

