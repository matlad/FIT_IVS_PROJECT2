# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/matla/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/matla/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/Linux_Data/Code/school/FIT_IVS_PROJECT2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug

# Include any dependencies generated for this target.
include googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make
googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: googletest-src/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-src/googletest/src/gtest_main.cc

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-src/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-src/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

googletest-build/googlemock/gtest/libgtest_maind.a: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
googletest-build/googlemock/gtest/libgtest_maind.a: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make
googletest-build/googlemock/gtest/libgtest_maind.a: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_maind.a"
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/build: googletest-build/googlemock/gtest/libgtest_maind.a

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/build

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/requires: googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/requires

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/clean:
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/clean

googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/depend:
	cd /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/Linux_Data/Code/school/FIT_IVS_PROJECT2 /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-src/googletest /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest /media/Linux_Data/Code/school/FIT_IVS_PROJECT2/cmake-build-debug/googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest_main.dir/depend

