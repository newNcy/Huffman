# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
SHELL = /data/data/com.termux/files/usr/bin/sh

# The CMake executable.
CMAKE_COMMAND = /data/data/com.termux/files/usr/bin/cmake

# The command to remove a file.
RM = /data/data/com.termux/files/usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/data/com.termux/files/home/Huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/data/com.termux/files/home/Huffman

# Include any dependencies generated for this target.
include CMakeFiles/huffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman.dir/flags.make

<<<<<<< HEAD
CMakeFiles/huffman.dir/src/decoder.cpp.obj: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/decoder.cpp.obj: src/decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman.dir/src/decoder.cpp.obj"
	/mingw64/bin/g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/src/decoder.cpp.obj -c /home/echo/Huffman/src/decoder.cpp

CMakeFiles/huffman.dir/src/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/src/decoder.cpp.i"
	/mingw64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/echo/Huffman/src/decoder.cpp > CMakeFiles/huffman.dir/src/decoder.cpp.i

CMakeFiles/huffman.dir/src/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/src/decoder.cpp.s"
	/mingw64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/echo/Huffman/src/decoder.cpp -o CMakeFiles/huffman.dir/src/decoder.cpp.s

CMakeFiles/huffman.dir/src/decoder.cpp.obj.requires:

.PHONY : CMakeFiles/huffman.dir/src/decoder.cpp.obj.requires

CMakeFiles/huffman.dir/src/decoder.cpp.obj.provides: CMakeFiles/huffman.dir/src/decoder.cpp.obj.requires
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/decoder.cpp.obj.provides.build
.PHONY : CMakeFiles/huffman.dir/src/decoder.cpp.obj.provides

CMakeFiles/huffman.dir/src/decoder.cpp.obj.provides.build: CMakeFiles/huffman.dir/src/decoder.cpp.obj


CMakeFiles/huffman.dir/src/encoder.cpp.obj: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/encoder.cpp.obj: src/encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/huffman.dir/src/encoder.cpp.obj"
	/mingw64/bin/g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/src/encoder.cpp.obj -c /home/echo/Huffman/src/encoder.cpp
=======
CMakeFiles/huffman.dir/src/encoder.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/encoder.cpp.o: src/encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman.dir/src/encoder.cpp.o"
	/data/data/com.termux/files/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/src/encoder.cpp.o -c /data/data/com.termux/files/home/Huffman/src/encoder.cpp
>>>>>>> 5ad7857d2130e2713451720b3adc374990e375ae

CMakeFiles/huffman.dir/src/encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/src/encoder.cpp.i"
	/data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Huffman/src/encoder.cpp > CMakeFiles/huffman.dir/src/encoder.cpp.i

CMakeFiles/huffman.dir/src/encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/src/encoder.cpp.s"
	/data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Huffman/src/encoder.cpp -o CMakeFiles/huffman.dir/src/encoder.cpp.s

CMakeFiles/huffman.dir/src/encoder.cpp.o.requires:

.PHONY : CMakeFiles/huffman.dir/src/encoder.cpp.o.requires

CMakeFiles/huffman.dir/src/encoder.cpp.o.provides: CMakeFiles/huffman.dir/src/encoder.cpp.o.requires
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/encoder.cpp.o.provides.build
.PHONY : CMakeFiles/huffman.dir/src/encoder.cpp.o.provides

CMakeFiles/huffman.dir/src/encoder.cpp.o.provides.build: CMakeFiles/huffman.dir/src/encoder.cpp.o


<<<<<<< HEAD
CMakeFiles/huffman.dir/src/main.cpp.obj: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/main.cpp.obj: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/echo/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/huffman.dir/src/main.cpp.obj"
	/mingw64/bin/g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/src/main.cpp.obj -c /home/echo/Huffman/src/main.cpp
=======
CMakeFiles/huffman.dir/src/main.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/huffman.dir/src/main.cpp.o"
	/data/data/com.termux/files/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman.dir/src/main.cpp.o -c /data/data/com.termux/files/home/Huffman/src/main.cpp
>>>>>>> 5ad7857d2130e2713451720b3adc374990e375ae

CMakeFiles/huffman.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/src/main.cpp.i"
	/data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Huffman/src/main.cpp > CMakeFiles/huffman.dir/src/main.cpp.i

CMakeFiles/huffman.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/src/main.cpp.s"
	/data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Huffman/src/main.cpp -o CMakeFiles/huffman.dir/src/main.cpp.s

CMakeFiles/huffman.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/huffman.dir/src/main.cpp.o.requires

CMakeFiles/huffman.dir/src/main.cpp.o.provides: CMakeFiles/huffman.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/huffman.dir/src/main.cpp.o.provides

CMakeFiles/huffman.dir/src/main.cpp.o.provides.build: CMakeFiles/huffman.dir/src/main.cpp.o


# Object files for target huffman
huffman_OBJECTS = \
<<<<<<< HEAD
"CMakeFiles/huffman.dir/src/decoder.cpp.obj" \
"CMakeFiles/huffman.dir/src/encoder.cpp.obj" \
"CMakeFiles/huffman.dir/src/main.cpp.obj"
=======
"CMakeFiles/huffman.dir/src/encoder.cpp.o" \
"CMakeFiles/huffman.dir/src/main.cpp.o"
>>>>>>> 5ad7857d2130e2713451720b3adc374990e375ae

# External object files for target huffman
huffman_EXTERNAL_OBJECTS =

<<<<<<< HEAD
huffman: CMakeFiles/huffman.dir/src/decoder.cpp.obj
huffman: CMakeFiles/huffman.dir/src/encoder.cpp.obj
huffman: CMakeFiles/huffman.dir/src/main.cpp.obj
huffman: CMakeFiles/huffman.dir/build.make
huffman: CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/echo/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable huffman"
=======
huffman: CMakeFiles/huffman.dir/src/encoder.cpp.o
huffman: CMakeFiles/huffman.dir/src/main.cpp.o
huffman: CMakeFiles/huffman.dir/build.make
huffman: CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/data/com.termux/files/home/Huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable huffman"
>>>>>>> 5ad7857d2130e2713451720b3adc374990e375ae
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman.dir/build: huffman

.PHONY : CMakeFiles/huffman.dir/build

<<<<<<< HEAD
CMakeFiles/huffman.dir/requires: CMakeFiles/huffman.dir/src/decoder.cpp.obj.requires
CMakeFiles/huffman.dir/requires: CMakeFiles/huffman.dir/src/encoder.cpp.obj.requires
CMakeFiles/huffman.dir/requires: CMakeFiles/huffman.dir/src/main.cpp.obj.requires
=======
CMakeFiles/huffman.dir/requires: CMakeFiles/huffman.dir/src/encoder.cpp.o.requires
CMakeFiles/huffman.dir/requires: CMakeFiles/huffman.dir/src/main.cpp.o.requires
>>>>>>> 5ad7857d2130e2713451720b3adc374990e375ae

.PHONY : CMakeFiles/huffman.dir/requires

CMakeFiles/huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman.dir/clean

CMakeFiles/huffman.dir/depend:
	cd /data/data/com.termux/files/home/Huffman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/data/com.termux/files/home/Huffman /data/data/com.termux/files/home/Huffman /data/data/com.termux/files/home/Huffman /data/data/com.termux/files/home/Huffman /data/data/com.termux/files/home/Huffman/CMakeFiles/huffman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huffman.dir/depend

