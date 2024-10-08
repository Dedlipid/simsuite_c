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
include CMakeFiles/integrators.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/integrators.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/integrators.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/integrators.dir/flags.make

CMakeFiles/integrators.dir/src/integrators/integrators.c.o: CMakeFiles/integrators.dir/flags.make
CMakeFiles/integrators.dir/src/integrators/integrators.c.o: ../src/integrators/integrators.c
CMakeFiles/integrators.dir/src/integrators/integrators.c.o: CMakeFiles/integrators.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/integrators.dir/src/integrators/integrators.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/integrators.dir/src/integrators/integrators.c.o -MF CMakeFiles/integrators.dir/src/integrators/integrators.c.o.d -o CMakeFiles/integrators.dir/src/integrators/integrators.c.o -c /home/shamaeib/simsuite_c/src/integrators/integrators.c

CMakeFiles/integrators.dir/src/integrators/integrators.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/integrators.dir/src/integrators/integrators.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shamaeib/simsuite_c/src/integrators/integrators.c > CMakeFiles/integrators.dir/src/integrators/integrators.c.i

CMakeFiles/integrators.dir/src/integrators/integrators.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/integrators.dir/src/integrators/integrators.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shamaeib/simsuite_c/src/integrators/integrators.c -o CMakeFiles/integrators.dir/src/integrators/integrators.c.s

CMakeFiles/integrators.dir/src/integrators/rk4.c.o: CMakeFiles/integrators.dir/flags.make
CMakeFiles/integrators.dir/src/integrators/rk4.c.o: ../src/integrators/rk4.c
CMakeFiles/integrators.dir/src/integrators/rk4.c.o: CMakeFiles/integrators.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/integrators.dir/src/integrators/rk4.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/integrators.dir/src/integrators/rk4.c.o -MF CMakeFiles/integrators.dir/src/integrators/rk4.c.o.d -o CMakeFiles/integrators.dir/src/integrators/rk4.c.o -c /home/shamaeib/simsuite_c/src/integrators/rk4.c

CMakeFiles/integrators.dir/src/integrators/rk4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/integrators.dir/src/integrators/rk4.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shamaeib/simsuite_c/src/integrators/rk4.c > CMakeFiles/integrators.dir/src/integrators/rk4.c.i

CMakeFiles/integrators.dir/src/integrators/rk4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/integrators.dir/src/integrators/rk4.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shamaeib/simsuite_c/src/integrators/rk4.c -o CMakeFiles/integrators.dir/src/integrators/rk4.c.s

# Object files for target integrators
integrators_OBJECTS = \
"CMakeFiles/integrators.dir/src/integrators/integrators.c.o" \
"CMakeFiles/integrators.dir/src/integrators/rk4.c.o"

# External object files for target integrators
integrators_EXTERNAL_OBJECTS =

libintegrators.a: CMakeFiles/integrators.dir/src/integrators/integrators.c.o
libintegrators.a: CMakeFiles/integrators.dir/src/integrators/rk4.c.o
libintegrators.a: CMakeFiles/integrators.dir/build.make
libintegrators.a: CMakeFiles/integrators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libintegrators.a"
	$(CMAKE_COMMAND) -P CMakeFiles/integrators.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/integrators.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/integrators.dir/build: libintegrators.a
.PHONY : CMakeFiles/integrators.dir/build

CMakeFiles/integrators.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/integrators.dir/cmake_clean.cmake
.PHONY : CMakeFiles/integrators.dir/clean

CMakeFiles/integrators.dir/depend:
	cd /home/shamaeib/simsuite_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build/CMakeFiles/integrators.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/integrators.dir/depend

