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
CMAKE_SOURCE_DIR = /home/lorenzo/CLionProjects/playfair

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lorenzo/CLionProjects/playfair/build

# Include any dependencies generated for this target.
include CMakeFiles/playfair.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/playfair.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/playfair.dir/flags.make

CMakeFiles/playfair.dir/main.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playfair.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/main.c.o   -c /home/lorenzo/CLionProjects/playfair/main.c

CMakeFiles/playfair.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/main.c > CMakeFiles/playfair.dir/main.c.i

CMakeFiles/playfair.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/main.c -o CMakeFiles/playfair.dir/main.c.s

CMakeFiles/playfair.dir/key.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/key.c.o: ../key.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/playfair.dir/key.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/key.c.o   -c /home/lorenzo/CLionProjects/playfair/key.c

CMakeFiles/playfair.dir/key.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/key.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/key.c > CMakeFiles/playfair.dir/key.c.i

CMakeFiles/playfair.dir/key.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/key.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/key.c -o CMakeFiles/playfair.dir/key.c.s

CMakeFiles/playfair.dir/file.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/file.c.o: ../file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/playfair.dir/file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/file.c.o   -c /home/lorenzo/CLionProjects/playfair/file.c

CMakeFiles/playfair.dir/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/file.c > CMakeFiles/playfair.dir/file.c.i

CMakeFiles/playfair.dir/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/file.c -o CMakeFiles/playfair.dir/file.c.s

CMakeFiles/playfair.dir/directory.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/directory.c.o: ../directory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/playfair.dir/directory.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/directory.c.o   -c /home/lorenzo/CLionProjects/playfair/directory.c

CMakeFiles/playfair.dir/directory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/directory.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/directory.c > CMakeFiles/playfair.dir/directory.c.i

CMakeFiles/playfair.dir/directory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/directory.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/directory.c -o CMakeFiles/playfair.dir/directory.c.s

CMakeFiles/playfair.dir/coding.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/coding.c.o: ../coding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/playfair.dir/coding.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/coding.c.o   -c /home/lorenzo/CLionProjects/playfair/coding.c

CMakeFiles/playfair.dir/coding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/coding.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/coding.c > CMakeFiles/playfair.dir/coding.c.i

CMakeFiles/playfair.dir/coding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/coding.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/coding.c -o CMakeFiles/playfair.dir/coding.c.s

CMakeFiles/playfair.dir/keygen.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/keygen.c.o: ../keygen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/playfair.dir/keygen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/keygen.c.o   -c /home/lorenzo/CLionProjects/playfair/keygen.c

CMakeFiles/playfair.dir/keygen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/keygen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/keygen.c > CMakeFiles/playfair.dir/keygen.c.i

CMakeFiles/playfair.dir/keygen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/keygen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/keygen.c -o CMakeFiles/playfair.dir/keygen.c.s

CMakeFiles/playfair.dir/mem_utils.c.o: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/mem_utils.c.o: ../mem_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/playfair.dir/mem_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/playfair.dir/mem_utils.c.o   -c /home/lorenzo/CLionProjects/playfair/mem_utils.c

CMakeFiles/playfair.dir/mem_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/mem_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lorenzo/CLionProjects/playfair/mem_utils.c > CMakeFiles/playfair.dir/mem_utils.c.i

CMakeFiles/playfair.dir/mem_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/mem_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lorenzo/CLionProjects/playfair/mem_utils.c -o CMakeFiles/playfair.dir/mem_utils.c.s

# Object files for target playfair
playfair_OBJECTS = \
"CMakeFiles/playfair.dir/main.c.o" \
"CMakeFiles/playfair.dir/key.c.o" \
"CMakeFiles/playfair.dir/file.c.o" \
"CMakeFiles/playfair.dir/directory.c.o" \
"CMakeFiles/playfair.dir/coding.c.o" \
"CMakeFiles/playfair.dir/keygen.c.o" \
"CMakeFiles/playfair.dir/mem_utils.c.o"

# External object files for target playfair
playfair_EXTERNAL_OBJECTS =

playfair: CMakeFiles/playfair.dir/main.c.o
playfair: CMakeFiles/playfair.dir/key.c.o
playfair: CMakeFiles/playfair.dir/file.c.o
playfair: CMakeFiles/playfair.dir/directory.c.o
playfair: CMakeFiles/playfair.dir/coding.c.o
playfair: CMakeFiles/playfair.dir/keygen.c.o
playfair: CMakeFiles/playfair.dir/mem_utils.c.o
playfair: CMakeFiles/playfair.dir/build.make
playfair: CMakeFiles/playfair.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lorenzo/CLionProjects/playfair/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable playfair"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playfair.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/playfair.dir/build: playfair

.PHONY : CMakeFiles/playfair.dir/build

CMakeFiles/playfair.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/playfair.dir/cmake_clean.cmake
.PHONY : CMakeFiles/playfair.dir/clean

CMakeFiles/playfair.dir/depend:
	cd /home/lorenzo/CLionProjects/playfair/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lorenzo/CLionProjects/playfair /home/lorenzo/CLionProjects/playfair /home/lorenzo/CLionProjects/playfair/build /home/lorenzo/CLionProjects/playfair/build /home/lorenzo/CLionProjects/playfair/build/CMakeFiles/playfair.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/playfair.dir/depend

