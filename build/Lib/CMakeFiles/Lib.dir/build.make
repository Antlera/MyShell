# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antlers/2019141480012/ysh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antlers/2019141480012/ysh/build

# Include any dependencies generated for this target.
include Lib/CMakeFiles/Lib.dir/depend.make

# Include the progress variables for this target.
include Lib/CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include Lib/CMakeFiles/Lib.dir/flags.make

Lib/CMakeFiles/Lib.dir/type_prompt.c.o: Lib/CMakeFiles/Lib.dir/flags.make
Lib/CMakeFiles/Lib.dir/type_prompt.c.o: ../Lib/type_prompt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Lib/CMakeFiles/Lib.dir/type_prompt.c.o"
	cd /home/antlers/2019141480012/ysh/build/Lib && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lib.dir/type_prompt.c.o   -c /home/antlers/2019141480012/ysh/Lib/type_prompt.c

Lib/CMakeFiles/Lib.dir/type_prompt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lib.dir/type_prompt.c.i"
	cd /home/antlers/2019141480012/ysh/build/Lib && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antlers/2019141480012/ysh/Lib/type_prompt.c > CMakeFiles/Lib.dir/type_prompt.c.i

Lib/CMakeFiles/Lib.dir/type_prompt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lib.dir/type_prompt.c.s"
	cd /home/antlers/2019141480012/ysh/build/Lib && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antlers/2019141480012/ysh/Lib/type_prompt.c -o CMakeFiles/Lib.dir/type_prompt.c.s

# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/type_prompt.c.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

lib/libLib.a: Lib/CMakeFiles/Lib.dir/type_prompt.c.o
lib/libLib.a: Lib/CMakeFiles/Lib.dir/build.make
lib/libLib.a: Lib/CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../lib/libLib.a"
	cd /home/antlers/2019141480012/ysh/build/Lib && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean_target.cmake
	cd /home/antlers/2019141480012/ysh/build/Lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Lib/CMakeFiles/Lib.dir/build: lib/libLib.a

.PHONY : Lib/CMakeFiles/Lib.dir/build

Lib/CMakeFiles/Lib.dir/clean:
	cd /home/antlers/2019141480012/ysh/build/Lib && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : Lib/CMakeFiles/Lib.dir/clean

Lib/CMakeFiles/Lib.dir/depend:
	cd /home/antlers/2019141480012/ysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antlers/2019141480012/ysh /home/antlers/2019141480012/ysh/Lib /home/antlers/2019141480012/ysh/build /home/antlers/2019141480012/ysh/build/Lib /home/antlers/2019141480012/ysh/build/Lib/CMakeFiles/Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Lib/CMakeFiles/Lib.dir/depend

