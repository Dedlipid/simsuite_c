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
include CMakeFiles/main_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_c.dir/flags.make

CMakeFiles/main_c.dir/src/main.c.o: CMakeFiles/main_c.dir/flags.make
CMakeFiles/main_c.dir/src/main.c.o: ../src/main.c
CMakeFiles/main_c.dir/src/main.c.o: CMakeFiles/main_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_c.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_c.dir/src/main.c.o -MF CMakeFiles/main_c.dir/src/main.c.o.d -o CMakeFiles/main_c.dir/src/main.c.o -c /home/shamaeib/simsuite_c/src/main.c

CMakeFiles/main_c.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_c.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shamaeib/simsuite_c/src/main.c > CMakeFiles/main_c.dir/src/main.c.i

CMakeFiles/main_c.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_c.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shamaeib/simsuite_c/src/main.c -o CMakeFiles/main_c.dir/src/main.c.s

# Object files for target main_c
main_c_OBJECTS = \
"CMakeFiles/main_c.dir/src/main.c.o"

# External object files for target main_c
main_c_EXTERNAL_OBJECTS =

main_c: CMakeFiles/main_c.dir/src/main.c.o
main_c: CMakeFiles/main_c.dir/build.make
main_c: libintegrators.a
main_c: libsystems.a
main_c: CMakeFiles/main_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_c.dir/build: main_c
.PHONY : CMakeFiles/main_c.dir/build

CMakeFiles/main_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_c.dir/clean

CMakeFiles/main_c.dir/depend:
	cd /home/shamaeib/simsuite_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build/CMakeFiles/main_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_c.dir/depend

