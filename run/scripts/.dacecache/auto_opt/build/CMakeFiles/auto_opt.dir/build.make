# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu20.04-skylake_avx512/gcc-9.3.0/cmake-3.23.1-vyfjulyyqe2a74k7unpe7hz55pirdj46/bin/cmake

# The command to remove a file.
RM = /shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu20.04-skylake_avx512/gcc-9.3.0/cmake-3.23.1-vyfjulyyqe2a74k7unpe7hz55pirdj46/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build

# Include any dependencies generated for this target.
include CMakeFiles/auto_opt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/auto_opt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/auto_opt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/auto_opt.dir/flags.make

CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o: CMakeFiles/auto_opt.dir/flags.make
CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o: /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp
CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o: CMakeFiles/auto_opt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o -MF CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o.d -o CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o -c /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp

CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp > CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.i

CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp -o CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.s

# Object files for target auto_opt
auto_opt_OBJECTS = \
"CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o"

# External object files for target auto_opt
auto_opt_EXTERNAL_OBJECTS =

libauto_opt.so: CMakeFiles/auto_opt.dir/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/src/cpu/auto_opt.cpp.o
libauto_opt.so: CMakeFiles/auto_opt.dir/build.make
libauto_opt.so: /usr/lib/gcc/x86_64-linux-gnu/9/libgomp.so
libauto_opt.so: /usr/lib/x86_64-linux-gnu/libpthread.so
libauto_opt.so: CMakeFiles/auto_opt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libauto_opt.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/auto_opt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/auto_opt.dir/build: libauto_opt.so
.PHONY : CMakeFiles/auto_opt.dir/build

CMakeFiles/auto_opt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/auto_opt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/auto_opt.dir/clean

CMakeFiles/auto_opt.dir/depend:
	cd /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/auto_opt/build/CMakeFiles/auto_opt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/auto_opt.dir/depend

