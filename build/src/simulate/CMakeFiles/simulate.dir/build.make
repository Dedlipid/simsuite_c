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
CMAKE_SOURCE_DIR = /home/shamaeib/simsuite_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shamaeib/simsuite_c/build

# Include any dependencies generated for this target.
include src/simulate/CMakeFiles/simulate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/simulate/CMakeFiles/simulate.dir/compiler_depend.make

# Include the progress variables for this target.
include src/simulate/CMakeFiles/simulate.dir/progress.make

# Include the compile flags for this target's objects.
include src/simulate/CMakeFiles/simulate.dir/flags.make

src/simulate/CMakeFiles/simulate.dir/simulate.c.o: src/simulate/CMakeFiles/simulate.dir/flags.make
src/simulate/CMakeFiles/simulate.dir/simulate.c.o: ../src/simulate/simulate.c
src/simulate/CMakeFiles/simulate.dir/simulate.c.o: src/simulate/CMakeFiles/simulate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/simulate/CMakeFiles/simulate.dir/simulate.c.o"
	cd /home/shamaeib/simsuite_c/build/src/simulate && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/simulate/CMakeFiles/simulate.dir/simulate.c.o -MF CMakeFiles/simulate.dir/simulate.c.o.d -o CMakeFiles/simulate.dir/simulate.c.o -c /home/shamaeib/simsuite_c/src/simulate/simulate.c

src/simulate/CMakeFiles/simulate.dir/simulate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simulate.dir/simulate.c.i"
	cd /home/shamaeib/simsuite_c/build/src/simulate && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shamaeib/simsuite_c/src/simulate/simulate.c > CMakeFiles/simulate.dir/simulate.c.i

src/simulate/CMakeFiles/simulate.dir/simulate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simulate.dir/simulate.c.s"
	cd /home/shamaeib/simsuite_c/build/src/simulate && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shamaeib/simsuite_c/src/simulate/simulate.c -o CMakeFiles/simulate.dir/simulate.c.s

# Object files for target simulate
simulate_OBJECTS = \
"CMakeFiles/simulate.dir/simulate.c.o"

# External object files for target simulate
simulate_EXTERNAL_OBJECTS =

src/simulate/libsimulate.a: src/simulate/CMakeFiles/simulate.dir/simulate.c.o
src/simulate/libsimulate.a: src/simulate/CMakeFiles/simulate.dir/build.make
src/simulate/libsimulate.a: src/simulate/CMakeFiles/simulate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsimulate.a"
	cd /home/shamaeib/simsuite_c/build/src/simulate && $(CMAKE_COMMAND) -P CMakeFiles/simulate.dir/cmake_clean_target.cmake
	cd /home/shamaeib/simsuite_c/build/src/simulate && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/simulate/CMakeFiles/simulate.dir/build: src/simulate/libsimulate.a
.PHONY : src/simulate/CMakeFiles/simulate.dir/build

src/simulate/CMakeFiles/simulate.dir/clean:
	cd /home/shamaeib/simsuite_c/build/src/simulate && $(CMAKE_COMMAND) -P CMakeFiles/simulate.dir/cmake_clean.cmake
.PHONY : src/simulate/CMakeFiles/simulate.dir/clean

src/simulate/CMakeFiles/simulate.dir/depend:
	cd /home/shamaeib/simsuite_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c/src/simulate /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build/src/simulate /home/shamaeib/simsuite_c/build/src/simulate/CMakeFiles/simulate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/simulate/CMakeFiles/simulate.dir/depend

