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
CMAKE_COMMAND = /shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-skylake_avx512/gcc-10.2.0/cmake-3.23.1-7fbvfttztcajdfy7n7uqczwpopzdbecr/bin/cmake

# The command to remove a file.
RM = /shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-skylake_avx512/gcc-10.2.0/cmake-3.23.1-7fbvfttztcajdfy7n7uqczwpopzdbecr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build

# Include any dependencies generated for this target.
include CMakeFiles/dacestub_bicg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dacestub_bicg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dacestub_bicg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dacestub_bicg.dir/flags.make

CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o: CMakeFiles/dacestub_bicg.dir/flags.make
CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o: /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen/tools/dacestub.cpp
CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o: CMakeFiles/dacestub_bicg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o"
	/shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-zen/gcc-7.5.0/gcc-10.2.0-s24g77kg7o56escg2hn44tvbrwxg7pwh/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o -MF CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o.d -o CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o -c /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen/tools/dacestub.cpp

CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.i"
	/shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-zen/gcc-7.5.0/gcc-10.2.0-s24g77kg7o56escg2hn44tvbrwxg7pwh/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen/tools/dacestub.cpp > CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.i

CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.s"
	/shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-zen/gcc-7.5.0/gcc-10.2.0-s24g77kg7o56escg2hn44tvbrwxg7pwh/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen/tools/dacestub.cpp -o CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.s

# Object files for target dacestub_bicg
dacestub_bicg_OBJECTS = \
"CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o"

# External object files for target dacestub_bicg
dacestub_bicg_EXTERNAL_OBJECTS =

libdacestub_bicg.so: CMakeFiles/dacestub_bicg.dir/tools/dacestub.cpp.o
libdacestub_bicg.so: CMakeFiles/dacestub_bicg.dir/build.make
libdacestub_bicg.so: /shared/home/ccuser/ReproducibilityChallenge/compile/spack-0.18.1/opt/spack/linux-ubuntu18.04-zen/gcc-7.5.0/gcc-10.2.0-s24g77kg7o56escg2hn44tvbrwxg7pwh/lib64/libgomp.so
libdacestub_bicg.so: /usr/lib/x86_64-linux-gnu/libpthread.so
libdacestub_bicg.so: CMakeFiles/dacestub_bicg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdacestub_bicg.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dacestub_bicg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dacestub_bicg.dir/build: libdacestub_bicg.so
.PHONY : CMakeFiles/dacestub_bicg.dir/build

CMakeFiles/dacestub_bicg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dacestub_bicg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dacestub_bicg.dir/clean

CMakeFiles/dacestub_bicg.dir/depend:
	cd /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen /shared/home/ccuser/ReproducibilityChallenge/compile/env-dace/lib/python3.8/site-packages/dace/codegen /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build /shared/home/ccuser/ReproducibilityChallenge/run/scripts/.dacecache/bicg/build/CMakeFiles/dacestub_bicg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dacestub_bicg.dir/depend

