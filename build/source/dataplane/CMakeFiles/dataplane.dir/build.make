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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/breeve/Desktop/笔记/src/sdn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/breeve/Desktop/笔记/src/sdn/build

# Include any dependencies generated for this target.
include source/dataplane/CMakeFiles/dataplane.dir/depend.make

# Include the progress variables for this target.
include source/dataplane/CMakeFiles/dataplane.dir/progress.make

# Include the compile flags for this target's objects.
include source/dataplane/CMakeFiles/dataplane.dir/flags.make

source/dataplane/CMakeFiles/dataplane.dir/device/device.c.o: source/dataplane/CMakeFiles/dataplane.dir/flags.make
source/dataplane/CMakeFiles/dataplane.dir/device/device.c.o: ../source/dataplane/device/device.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/breeve/Desktop/笔记/src/sdn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/dataplane/CMakeFiles/dataplane.dir/device/device.c.o"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dataplane.dir/device/device.c.o   -c /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/device/device.c

source/dataplane/CMakeFiles/dataplane.dir/device/device.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dataplane.dir/device/device.c.i"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/device/device.c > CMakeFiles/dataplane.dir/device/device.c.i

source/dataplane/CMakeFiles/dataplane.dir/device/device.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dataplane.dir/device/device.c.s"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/device/device.c -o CMakeFiles/dataplane.dir/device/device.c.s

source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.o: source/dataplane/CMakeFiles/dataplane.dir/flags.make
source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.o: ../source/dataplane/vswitch/vswitch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/breeve/Desktop/笔记/src/sdn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.o"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dataplane.dir/vswitch/vswitch.c.o   -c /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/vswitch/vswitch.c

source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dataplane.dir/vswitch/vswitch.c.i"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/vswitch/vswitch.c > CMakeFiles/dataplane.dir/vswitch/vswitch.c.i

source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dataplane.dir/vswitch/vswitch.c.s"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/vswitch/vswitch.c -o CMakeFiles/dataplane.dir/vswitch/vswitch.c.s

source/dataplane/CMakeFiles/dataplane.dir/init/main.c.o: source/dataplane/CMakeFiles/dataplane.dir/flags.make
source/dataplane/CMakeFiles/dataplane.dir/init/main.c.o: ../source/dataplane/init/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/breeve/Desktop/笔记/src/sdn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/dataplane/CMakeFiles/dataplane.dir/init/main.c.o"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dataplane.dir/init/main.c.o   -c /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/init/main.c

source/dataplane/CMakeFiles/dataplane.dir/init/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dataplane.dir/init/main.c.i"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/init/main.c > CMakeFiles/dataplane.dir/init/main.c.i

source/dataplane/CMakeFiles/dataplane.dir/init/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dataplane.dir/init/main.c.s"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/breeve/Desktop/笔记/src/sdn/source/dataplane/init/main.c -o CMakeFiles/dataplane.dir/init/main.c.s

# Object files for target dataplane
dataplane_OBJECTS = \
"CMakeFiles/dataplane.dir/device/device.c.o" \
"CMakeFiles/dataplane.dir/vswitch/vswitch.c.o" \
"CMakeFiles/dataplane.dir/init/main.c.o"

# External object files for target dataplane
dataplane_EXTERNAL_OBJECTS =

source/dataplane/dataplane: source/dataplane/CMakeFiles/dataplane.dir/device/device.c.o
source/dataplane/dataplane: source/dataplane/CMakeFiles/dataplane.dir/vswitch/vswitch.c.o
source/dataplane/dataplane: source/dataplane/CMakeFiles/dataplane.dir/init/main.c.o
source/dataplane/dataplane: source/dataplane/CMakeFiles/dataplane.dir/build.make
source/dataplane/dataplane: source/lib/libbase/libbase.dylib
source/dataplane/dataplane: source/dataplane/CMakeFiles/dataplane.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/breeve/Desktop/笔记/src/sdn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable dataplane"
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dataplane.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/dataplane/CMakeFiles/dataplane.dir/build: source/dataplane/dataplane

.PHONY : source/dataplane/CMakeFiles/dataplane.dir/build

source/dataplane/CMakeFiles/dataplane.dir/clean:
	cd /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane && $(CMAKE_COMMAND) -P CMakeFiles/dataplane.dir/cmake_clean.cmake
.PHONY : source/dataplane/CMakeFiles/dataplane.dir/clean

source/dataplane/CMakeFiles/dataplane.dir/depend:
	cd /Users/breeve/Desktop/笔记/src/sdn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/breeve/Desktop/笔记/src/sdn /Users/breeve/Desktop/笔记/src/sdn/source/dataplane /Users/breeve/Desktop/笔记/src/sdn/build /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane /Users/breeve/Desktop/笔记/src/sdn/build/source/dataplane/CMakeFiles/dataplane.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/dataplane/CMakeFiles/dataplane.dir/depend

