# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/yuanxinyu/cpp_syntax

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/yuanxinyu/cpp_syntax/build

# Include any dependencies generated for this target.
include 01-basic/CMakeFiles/const.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 01-basic/CMakeFiles/const.dir/compiler_depend.make

# Include the progress variables for this target.
include 01-basic/CMakeFiles/const.dir/progress.make

# Include the compile flags for this target's objects.
include 01-basic/CMakeFiles/const.dir/flags.make

01-basic/CMakeFiles/const.dir/const.cpp.o: 01-basic/CMakeFiles/const.dir/flags.make
01-basic/CMakeFiles/const.dir/const.cpp.o: /Users/mac/yuanxinyu/cpp_syntax/01-basic/const.cpp
01-basic/CMakeFiles/const.dir/const.cpp.o: 01-basic/CMakeFiles/const.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/yuanxinyu/cpp_syntax/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 01-basic/CMakeFiles/const.dir/const.cpp.o"
	cd /Users/mac/yuanxinyu/cpp_syntax/build/01-basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 01-basic/CMakeFiles/const.dir/const.cpp.o -MF CMakeFiles/const.dir/const.cpp.o.d -o CMakeFiles/const.dir/const.cpp.o -c /Users/mac/yuanxinyu/cpp_syntax/01-basic/const.cpp

01-basic/CMakeFiles/const.dir/const.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/const.dir/const.cpp.i"
	cd /Users/mac/yuanxinyu/cpp_syntax/build/01-basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/yuanxinyu/cpp_syntax/01-basic/const.cpp > CMakeFiles/const.dir/const.cpp.i

01-basic/CMakeFiles/const.dir/const.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/const.dir/const.cpp.s"
	cd /Users/mac/yuanxinyu/cpp_syntax/build/01-basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/yuanxinyu/cpp_syntax/01-basic/const.cpp -o CMakeFiles/const.dir/const.cpp.s

# Object files for target const
const_OBJECTS = \
"CMakeFiles/const.dir/const.cpp.o"

# External object files for target const
const_EXTERNAL_OBJECTS =

01-basic/const: 01-basic/CMakeFiles/const.dir/const.cpp.o
01-basic/const: 01-basic/CMakeFiles/const.dir/build.make
01-basic/const: 01-basic/CMakeFiles/const.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/yuanxinyu/cpp_syntax/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable const"
	cd /Users/mac/yuanxinyu/cpp_syntax/build/01-basic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/const.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
01-basic/CMakeFiles/const.dir/build: 01-basic/const
.PHONY : 01-basic/CMakeFiles/const.dir/build

01-basic/CMakeFiles/const.dir/clean:
	cd /Users/mac/yuanxinyu/cpp_syntax/build/01-basic && $(CMAKE_COMMAND) -P CMakeFiles/const.dir/cmake_clean.cmake
.PHONY : 01-basic/CMakeFiles/const.dir/clean

01-basic/CMakeFiles/const.dir/depend:
	cd /Users/mac/yuanxinyu/cpp_syntax/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/yuanxinyu/cpp_syntax /Users/mac/yuanxinyu/cpp_syntax/01-basic /Users/mac/yuanxinyu/cpp_syntax/build /Users/mac/yuanxinyu/cpp_syntax/build/01-basic /Users/mac/yuanxinyu/cpp_syntax/build/01-basic/CMakeFiles/const.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 01-basic/CMakeFiles/const.dir/depend

