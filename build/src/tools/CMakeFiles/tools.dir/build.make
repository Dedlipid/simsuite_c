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
include src/tools/CMakeFiles/tools.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/tools/CMakeFiles/tools.dir/compiler_depend.make

# Include the progress variables for this target.
include src/tools/CMakeFiles/tools.dir/progress.make

# Include the compile flags for this target's objects.
include src/tools/CMakeFiles/tools.dir/flags.make

src/tools/CMakeFiles/tools.dir/tool.c.o: src/tools/CMakeFiles/tools.dir/flags.make
src/tools/CMakeFiles/tools.dir/tool.c.o: ../src/tools/tool.c
src/tools/CMakeFiles/tools.dir/tool.c.o: src/tools/CMakeFiles/tools.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/tools/CMakeFiles/tools.dir/tool.c.o"
	cd /home/shamaeib/simsuite_c/build/src/tools && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/tools/CMakeFiles/tools.dir/tool.c.o -MF CMakeFiles/tools.dir/tool.c.o.d -o CMakeFiles/tools.dir/tool.c.o -c /home/shamaeib/simsuite_c/src/tools/tool.c

src/tools/CMakeFiles/tools.dir/tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tools.dir/tool.c.i"
	cd /home/shamaeib/simsuite_c/build/src/tools && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shamaeib/simsuite_c/src/tools/tool.c > CMakeFiles/tools.dir/tool.c.i

src/tools/CMakeFiles/tools.dir/tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tools.dir/tool.c.s"
	cd /home/shamaeib/simsuite_c/build/src/tools && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shamaeib/simsuite_c/src/tools/tool.c -o CMakeFiles/tools.dir/tool.c.s

# Object files for target tools
tools_OBJECTS = \
"CMakeFiles/tools.dir/tool.c.o"

# External object files for target tools
tools_EXTERNAL_OBJECTS =

src/tools/libtools.a: src/tools/CMakeFiles/tools.dir/tool.c.o
src/tools/libtools.a: src/tools/CMakeFiles/tools.dir/build.make
src/tools/libtools.a: src/tools/CMakeFiles/tools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shamaeib/simsuite_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtools.a"
	cd /home/shamaeib/simsuite_c/build/src/tools && $(CMAKE_COMMAND) -P CMakeFiles/tools.dir/cmake_clean_target.cmake
	cd /home/shamaeib/simsuite_c/build/src/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tools/CMakeFiles/tools.dir/build: src/tools/libtools.a
.PHONY : src/tools/CMakeFiles/tools.dir/build

src/tools/CMakeFiles/tools.dir/clean:
	cd /home/shamaeib/simsuite_c/build/src/tools && $(CMAKE_COMMAND) -P CMakeFiles/tools.dir/cmake_clean.cmake
.PHONY : src/tools/CMakeFiles/tools.dir/clean

src/tools/CMakeFiles/tools.dir/depend:
	cd /home/shamaeib/simsuite_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shamaeib/simsuite_c /home/shamaeib/simsuite_c/src/tools /home/shamaeib/simsuite_c/build /home/shamaeib/simsuite_c/build/src/tools /home/shamaeib/simsuite_c/build/src/tools/CMakeFiles/tools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tools/CMakeFiles/tools.dir/depend

