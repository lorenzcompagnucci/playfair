# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\loren\CLionProjects\playfair

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\loren\CLionProjects\playfair\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/playfair.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/playfair.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/playfair.dir/flags.make

CMakeFiles/playfair.dir/main.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playfair.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\main.c.obj -c C:\Users\loren\CLionProjects\playfair\main.c

CMakeFiles/playfair.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\main.c > CMakeFiles\playfair.dir\main.c.i

CMakeFiles/playfair.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\main.c -o CMakeFiles\playfair.dir\main.c.s

CMakeFiles/playfair.dir/key.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/key.c.obj: ../key.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/playfair.dir/key.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\key.c.obj -c C:\Users\loren\CLionProjects\playfair\key.c

CMakeFiles/playfair.dir/key.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/key.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\key.c > CMakeFiles\playfair.dir\key.c.i

CMakeFiles/playfair.dir/key.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/key.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\key.c -o CMakeFiles\playfair.dir\key.c.s

CMakeFiles/playfair.dir/file.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/file.c.obj: ../file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/playfair.dir/file.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\file.c.obj -c C:\Users\loren\CLionProjects\playfair\file.c

CMakeFiles/playfair.dir/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/file.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\file.c > CMakeFiles\playfair.dir\file.c.i

CMakeFiles/playfair.dir/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/file.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\file.c -o CMakeFiles\playfair.dir\file.c.s

CMakeFiles/playfair.dir/directory.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/directory.c.obj: ../directory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/playfair.dir/directory.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\directory.c.obj -c C:\Users\loren\CLionProjects\playfair\directory.c

CMakeFiles/playfair.dir/directory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/directory.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\directory.c > CMakeFiles\playfair.dir\directory.c.i

CMakeFiles/playfair.dir/directory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/directory.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\directory.c -o CMakeFiles\playfair.dir\directory.c.s

CMakeFiles/playfair.dir/decoding.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/decoding.c.obj: ../decoding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/playfair.dir/decoding.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\decoding.c.obj -c C:\Users\loren\CLionProjects\playfair\decoding.c

CMakeFiles/playfair.dir/decoding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/decoding.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\decoding.c > CMakeFiles\playfair.dir\decoding.c.i

CMakeFiles/playfair.dir/decoding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/decoding.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\decoding.c -o CMakeFiles\playfair.dir\decoding.c.s

CMakeFiles/playfair.dir/keygen.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/keygen.c.obj: ../keygen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/playfair.dir/keygen.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\keygen.c.obj -c C:\Users\loren\CLionProjects\playfair\keygen.c

CMakeFiles/playfair.dir/keygen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/keygen.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\keygen.c > CMakeFiles\playfair.dir\keygen.c.i

CMakeFiles/playfair.dir/keygen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/keygen.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\keygen.c -o CMakeFiles\playfair.dir\keygen.c.s

CMakeFiles/playfair.dir/mem_utils.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/mem_utils.c.obj: ../mem_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/playfair.dir/mem_utils.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\mem_utils.c.obj -c C:\Users\loren\CLionProjects\playfair\mem_utils.c

CMakeFiles/playfair.dir/mem_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/mem_utils.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\mem_utils.c > CMakeFiles\playfair.dir\mem_utils.c.i

CMakeFiles/playfair.dir/mem_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/mem_utils.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\mem_utils.c -o CMakeFiles\playfair.dir\mem_utils.c.s

CMakeFiles/playfair.dir/elab_utils.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/elab_utils.c.obj: ../elab_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/playfair.dir/elab_utils.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\elab_utils.c.obj -c C:\Users\loren\CLionProjects\playfair\elab_utils.c

CMakeFiles/playfair.dir/elab_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/elab_utils.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\elab_utils.c > CMakeFiles\playfair.dir\elab_utils.c.i

CMakeFiles/playfair.dir/elab_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/elab_utils.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\elab_utils.c -o CMakeFiles\playfair.dir\elab_utils.c.s

CMakeFiles/playfair.dir/encoding.c.obj: CMakeFiles/playfair.dir/flags.make
CMakeFiles/playfair.dir/encoding.c.obj: ../encoding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/playfair.dir/encoding.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\playfair.dir\encoding.c.obj -c C:\Users\loren\CLionProjects\playfair\encoding.c

CMakeFiles/playfair.dir/encoding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playfair.dir/encoding.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\loren\CLionProjects\playfair\encoding.c > CMakeFiles\playfair.dir\encoding.c.i

CMakeFiles/playfair.dir/encoding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playfair.dir/encoding.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\loren\CLionProjects\playfair\encoding.c -o CMakeFiles\playfair.dir\encoding.c.s

# Object files for target playfair
playfair_OBJECTS = \
"CMakeFiles/playfair.dir/main.c.obj" \
"CMakeFiles/playfair.dir/key.c.obj" \
"CMakeFiles/playfair.dir/file.c.obj" \
"CMakeFiles/playfair.dir/directory.c.obj" \
"CMakeFiles/playfair.dir/decoding.c.obj" \
"CMakeFiles/playfair.dir/keygen.c.obj" \
"CMakeFiles/playfair.dir/mem_utils.c.obj" \
"CMakeFiles/playfair.dir/elab_utils.c.obj" \
"CMakeFiles/playfair.dir/encoding.c.obj"

# External object files for target playfair
playfair_EXTERNAL_OBJECTS =

playfair.exe: CMakeFiles/playfair.dir/main.c.obj
playfair.exe: CMakeFiles/playfair.dir/key.c.obj
playfair.exe: CMakeFiles/playfair.dir/file.c.obj
playfair.exe: CMakeFiles/playfair.dir/directory.c.obj
playfair.exe: CMakeFiles/playfair.dir/decoding.c.obj
playfair.exe: CMakeFiles/playfair.dir/keygen.c.obj
playfair.exe: CMakeFiles/playfair.dir/mem_utils.c.obj
playfair.exe: CMakeFiles/playfair.dir/elab_utils.c.obj
playfair.exe: CMakeFiles/playfair.dir/encoding.c.obj
playfair.exe: CMakeFiles/playfair.dir/build.make
playfair.exe: CMakeFiles/playfair.dir/linklibs.rsp
playfair.exe: CMakeFiles/playfair.dir/objects1.rsp
playfair.exe: CMakeFiles/playfair.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable playfair.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\playfair.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/playfair.dir/build: playfair.exe

.PHONY : CMakeFiles/playfair.dir/build

CMakeFiles/playfair.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\playfair.dir\cmake_clean.cmake
.PHONY : CMakeFiles/playfair.dir/clean

CMakeFiles/playfair.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\loren\CLionProjects\playfair C:\Users\loren\CLionProjects\playfair C:\Users\loren\CLionProjects\playfair\cmake-build-debug C:\Users\loren\CLionProjects\playfair\cmake-build-debug C:\Users\loren\CLionProjects\playfair\cmake-build-debug\CMakeFiles\playfair.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/playfair.dir/depend

