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
include MyShell/CMakeFiles/MyShell.dir/depend.make

# Include the progress variables for this target.
include MyShell/CMakeFiles/MyShell.dir/progress.make

# Include the compile flags for this target's objects.
include MyShell/CMakeFiles/MyShell.dir/flags.make

MyShell/CMakeFiles/MyShell.dir/type_prompt.c.o: MyShell/CMakeFiles/MyShell.dir/flags.make
MyShell/CMakeFiles/MyShell.dir/type_prompt.c.o: ../MyShell/type_prompt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object MyShell/CMakeFiles/MyShell.dir/type_prompt.c.o"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/type_prompt.c.o   -c /home/antlers/2019141480012/ysh/MyShell/type_prompt.c

MyShell/CMakeFiles/MyShell.dir/type_prompt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/type_prompt.c.i"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antlers/2019141480012/ysh/MyShell/type_prompt.c > CMakeFiles/MyShell.dir/type_prompt.c.i

MyShell/CMakeFiles/MyShell.dir/type_prompt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/type_prompt.c.s"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antlers/2019141480012/ysh/MyShell/type_prompt.c -o CMakeFiles/MyShell.dir/type_prompt.c.s

MyShell/CMakeFiles/MyShell.dir/read_command.c.o: MyShell/CMakeFiles/MyShell.dir/flags.make
MyShell/CMakeFiles/MyShell.dir/read_command.c.o: ../MyShell/read_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object MyShell/CMakeFiles/MyShell.dir/read_command.c.o"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/read_command.c.o   -c /home/antlers/2019141480012/ysh/MyShell/read_command.c

MyShell/CMakeFiles/MyShell.dir/read_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/read_command.c.i"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antlers/2019141480012/ysh/MyShell/read_command.c > CMakeFiles/MyShell.dir/read_command.c.i

MyShell/CMakeFiles/MyShell.dir/read_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/read_command.c.s"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antlers/2019141480012/ysh/MyShell/read_command.c -o CMakeFiles/MyShell.dir/read_command.c.s

MyShell/CMakeFiles/MyShell.dir/builtin_command.c.o: MyShell/CMakeFiles/MyShell.dir/flags.make
MyShell/CMakeFiles/MyShell.dir/builtin_command.c.o: ../MyShell/builtin_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object MyShell/CMakeFiles/MyShell.dir/builtin_command.c.o"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/builtin_command.c.o   -c /home/antlers/2019141480012/ysh/MyShell/builtin_command.c

MyShell/CMakeFiles/MyShell.dir/builtin_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/builtin_command.c.i"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antlers/2019141480012/ysh/MyShell/builtin_command.c > CMakeFiles/MyShell.dir/builtin_command.c.i

MyShell/CMakeFiles/MyShell.dir/builtin_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/builtin_command.c.s"
	cd /home/antlers/2019141480012/ysh/build/MyShell && /bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antlers/2019141480012/ysh/MyShell/builtin_command.c -o CMakeFiles/MyShell.dir/builtin_command.c.s

# Object files for target MyShell
MyShell_OBJECTS = \
"CMakeFiles/MyShell.dir/type_prompt.c.o" \
"CMakeFiles/MyShell.dir/read_command.c.o" \
"CMakeFiles/MyShell.dir/builtin_command.c.o"

# External object files for target MyShell
MyShell_EXTERNAL_OBJECTS =

lib/libMyShell.a: MyShell/CMakeFiles/MyShell.dir/type_prompt.c.o
lib/libMyShell.a: MyShell/CMakeFiles/MyShell.dir/read_command.c.o
lib/libMyShell.a: MyShell/CMakeFiles/MyShell.dir/builtin_command.c.o
lib/libMyShell.a: MyShell/CMakeFiles/MyShell.dir/build.make
lib/libMyShell.a: MyShell/CMakeFiles/MyShell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antlers/2019141480012/ysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library ../lib/libMyShell.a"
	cd /home/antlers/2019141480012/ysh/build/MyShell && $(CMAKE_COMMAND) -P CMakeFiles/MyShell.dir/cmake_clean_target.cmake
	cd /home/antlers/2019141480012/ysh/build/MyShell && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyShell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MyShell/CMakeFiles/MyShell.dir/build: lib/libMyShell.a

.PHONY : MyShell/CMakeFiles/MyShell.dir/build

MyShell/CMakeFiles/MyShell.dir/clean:
	cd /home/antlers/2019141480012/ysh/build/MyShell && $(CMAKE_COMMAND) -P CMakeFiles/MyShell.dir/cmake_clean.cmake
.PHONY : MyShell/CMakeFiles/MyShell.dir/clean

MyShell/CMakeFiles/MyShell.dir/depend:
	cd /home/antlers/2019141480012/ysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antlers/2019141480012/ysh /home/antlers/2019141480012/ysh/MyShell /home/antlers/2019141480012/ysh/build /home/antlers/2019141480012/ysh/build/MyShell /home/antlers/2019141480012/ysh/build/MyShell/CMakeFiles/MyShell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MyShell/CMakeFiles/MyShell.dir/depend

