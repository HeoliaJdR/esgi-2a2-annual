# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\rayan\Desktop\projet C annuel"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.c.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.c.obj: CMakeFiles/untitled.dir/includes_C.rsp
CMakeFiles/untitled.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled.dir\main.c.obj   -c "C:\Users\rayan\Desktop\projet C annuel\main.c"

CMakeFiles/untitled.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\rayan\Desktop\projet C annuel\main.c" > CMakeFiles\untitled.dir\main.c.i

CMakeFiles/untitled.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\rayan\Desktop\projet C annuel\main.c" -o CMakeFiles\untitled.dir\main.c.s

CMakeFiles/untitled.dir/main.c.obj.requires:

.PHONY : CMakeFiles/untitled.dir/main.c.obj.requires

CMakeFiles/untitled.dir/main.c.obj.provides: CMakeFiles/untitled.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\untitled.dir\build.make CMakeFiles/untitled.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/untitled.dir/main.c.obj.provides

CMakeFiles/untitled.dir/main.c.obj.provides.build: CMakeFiles/untitled.dir/main.c.obj


CMakeFiles/untitled.dir/qrcodegen.c.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/qrcodegen.c.obj: CMakeFiles/untitled.dir/includes_C.rsp
CMakeFiles/untitled.dir/qrcodegen.c.obj: ../qrcodegen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled.dir/qrcodegen.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled.dir\qrcodegen.c.obj   -c "C:\Users\rayan\Desktop\projet C annuel\qrcodegen.c"

CMakeFiles/untitled.dir/qrcodegen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/qrcodegen.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\rayan\Desktop\projet C annuel\qrcodegen.c" > CMakeFiles\untitled.dir\qrcodegen.c.i

CMakeFiles/untitled.dir/qrcodegen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/qrcodegen.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\rayan\Desktop\projet C annuel\qrcodegen.c" -o CMakeFiles\untitled.dir\qrcodegen.c.s

CMakeFiles/untitled.dir/qrcodegen.c.obj.requires:

.PHONY : CMakeFiles/untitled.dir/qrcodegen.c.obj.requires

CMakeFiles/untitled.dir/qrcodegen.c.obj.provides: CMakeFiles/untitled.dir/qrcodegen.c.obj.requires
	$(MAKE) -f CMakeFiles\untitled.dir\build.make CMakeFiles/untitled.dir/qrcodegen.c.obj.provides.build
.PHONY : CMakeFiles/untitled.dir/qrcodegen.c.obj.provides

CMakeFiles/untitled.dir/qrcodegen.c.obj.provides.build: CMakeFiles/untitled.dir/qrcodegen.c.obj


CMakeFiles/untitled.dir/function.c.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/function.c.obj: CMakeFiles/untitled.dir/includes_C.rsp
CMakeFiles/untitled.dir/function.c.obj: ../function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled.dir/function.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled.dir\function.c.obj   -c "C:\Users\rayan\Desktop\projet C annuel\function.c"

CMakeFiles/untitled.dir/function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/function.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\rayan\Desktop\projet C annuel\function.c" > CMakeFiles\untitled.dir\function.c.i

CMakeFiles/untitled.dir/function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/function.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\rayan\Desktop\projet C annuel\function.c" -o CMakeFiles\untitled.dir\function.c.s

CMakeFiles/untitled.dir/function.c.obj.requires:

.PHONY : CMakeFiles/untitled.dir/function.c.obj.requires

CMakeFiles/untitled.dir/function.c.obj.provides: CMakeFiles/untitled.dir/function.c.obj.requires
	$(MAKE) -f CMakeFiles\untitled.dir\build.make CMakeFiles/untitled.dir/function.c.obj.provides.build
.PHONY : CMakeFiles/untitled.dir/function.c.obj.provides

CMakeFiles/untitled.dir/function.c.obj.provides.build: CMakeFiles/untitled.dir/function.c.obj


# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.c.obj" \
"CMakeFiles/untitled.dir/qrcodegen.c.obj" \
"CMakeFiles/untitled.dir/function.c.obj"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled.exe: CMakeFiles/untitled.dir/main.c.obj
untitled.exe: CMakeFiles/untitled.dir/qrcodegen.c.obj
untitled.exe: CMakeFiles/untitled.dir/function.c.obj
untitled.exe: CMakeFiles/untitled.dir/build.make
untitled.exe: CMakeFiles/untitled.dir/linklibs.rsp
untitled.exe: CMakeFiles/untitled.dir/objects1.rsp
untitled.exe: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable untitled.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled.exe

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/main.c.obj.requires
CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/qrcodegen.c.obj.requires
CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/function.c.obj.requires

.PHONY : CMakeFiles/untitled.dir/requires

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\rayan\Desktop\projet C annuel" "C:\Users\rayan\Desktop\projet C annuel" "C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug" "C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug" "C:\Users\rayan\Desktop\projet C annuel\cmake-build-debug\CMakeFiles\untitled.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

