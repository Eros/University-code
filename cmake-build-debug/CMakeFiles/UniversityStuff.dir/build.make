# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/Users/george/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/george/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/george/Documents/Programming/C/UniversityStuff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UniversityStuff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UniversityStuff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UniversityStuff.dir/flags.make

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o: CMakeFiles/UniversityStuff.dir/flags.make
CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o: ../StringsAndStuff.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o   -c /Users/george/Documents/Programming/C/UniversityStuff/StringsAndStuff.c

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/george/Documents/Programming/C/UniversityStuff/StringsAndStuff.c > CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.i

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/george/Documents/Programming/C/UniversityStuff/StringsAndStuff.c -o CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.s

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.requires:

.PHONY : CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.requires

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.provides: CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.requires
	$(MAKE) -f CMakeFiles/UniversityStuff.dir/build.make CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.provides.build
.PHONY : CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.provides

CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.provides.build: CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o


# Object files for target UniversityStuff
UniversityStuff_OBJECTS = \
"CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o"

# External object files for target UniversityStuff
UniversityStuff_EXTERNAL_OBJECTS =

UniversityStuff: CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o
UniversityStuff: CMakeFiles/UniversityStuff.dir/build.make
UniversityStuff: CMakeFiles/UniversityStuff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable UniversityStuff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UniversityStuff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UniversityStuff.dir/build: UniversityStuff

.PHONY : CMakeFiles/UniversityStuff.dir/build

CMakeFiles/UniversityStuff.dir/requires: CMakeFiles/UniversityStuff.dir/StringsAndStuff.c.o.requires

.PHONY : CMakeFiles/UniversityStuff.dir/requires

CMakeFiles/UniversityStuff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UniversityStuff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UniversityStuff.dir/clean

CMakeFiles/UniversityStuff.dir/depend:
	cd /Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/george/Documents/Programming/C/UniversityStuff /Users/george/Documents/Programming/C/UniversityStuff /Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug /Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug /Users/george/Documents/Programming/C/UniversityStuff/cmake-build-debug/CMakeFiles/UniversityStuff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UniversityStuff.dir/depend

