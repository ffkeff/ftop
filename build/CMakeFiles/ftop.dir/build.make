# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/ffkeff/projects/ftop/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ffkeff/projects/ftop/build

# Include any dependencies generated for this target.
include CMakeFiles/ftop.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ftop.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ftop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ftop.dir/flags.make

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o: CMakeFiles/ftop.dir/flags.make
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o: /home/ffkeff/projects/ftop/src/ftop.c
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o: CMakeFiles/ftop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ffkeff/projects/ftop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o -MF CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o.d -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o -c /home/ffkeff/projects/ftop/src/ftop.c

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ffkeff/projects/ftop/src/ftop.c > CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.i

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ffkeff/projects/ftop/src/ftop.c -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.s

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o: CMakeFiles/ftop.dir/flags.make
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o: /home/ffkeff/projects/ftop/src/procdriver.c
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o: CMakeFiles/ftop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ffkeff/projects/ftop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o -MF CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o.d -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o -c /home/ffkeff/projects/ftop/src/procdriver.c

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ffkeff/projects/ftop/src/procdriver.c > CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.i

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ffkeff/projects/ftop/src/procdriver.c -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.s

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o: CMakeFiles/ftop.dir/flags.make
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o: /home/ffkeff/projects/ftop/src/process.c
CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o: CMakeFiles/ftop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ffkeff/projects/ftop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o -MF CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o.d -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o -c /home/ffkeff/projects/ftop/src/process.c

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ffkeff/projects/ftop/src/process.c > CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.i

CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ffkeff/projects/ftop/src/process.c -o CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.s

# Object files for target ftop
ftop_OBJECTS = \
"CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o" \
"CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o" \
"CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o"

# External object files for target ftop
ftop_EXTERNAL_OBJECTS =

ftop: CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/ftop.c.o
ftop: CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/procdriver.c.o
ftop: CMakeFiles/ftop.dir/home/ffkeff/projects/ftop/src/process.c.o
ftop: CMakeFiles/ftop.dir/build.make
ftop: CMakeFiles/ftop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ffkeff/projects/ftop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ftop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ftop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ftop.dir/build: ftop
.PHONY : CMakeFiles/ftop.dir/build

CMakeFiles/ftop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ftop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ftop.dir/clean

CMakeFiles/ftop.dir/depend:
	cd /home/ffkeff/projects/ftop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ffkeff/projects/ftop/cmake /home/ffkeff/projects/ftop/cmake /home/ffkeff/projects/ftop/build /home/ffkeff/projects/ftop/build /home/ffkeff/projects/ftop/build/CMakeFiles/ftop.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ftop.dir/depend
