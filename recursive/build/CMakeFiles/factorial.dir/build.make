# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mcx/data_structure_algorithm/data_struct_al/recursive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mcx/data_structure_algorithm/data_struct_al/recursive/build

# Include any dependencies generated for this target.
include CMakeFiles/factorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/factorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/factorial.dir/flags.make

CMakeFiles/factorial.dir/factorial.cpp.o: CMakeFiles/factorial.dir/flags.make
CMakeFiles/factorial.dir/factorial.cpp.o: ../factorial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mcx/data_structure_algorithm/data_struct_al/recursive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/factorial.dir/factorial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/factorial.dir/factorial.cpp.o -c /home/mcx/data_structure_algorithm/data_struct_al/recursive/factorial.cpp

CMakeFiles/factorial.dir/factorial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factorial.dir/factorial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mcx/data_structure_algorithm/data_struct_al/recursive/factorial.cpp > CMakeFiles/factorial.dir/factorial.cpp.i

CMakeFiles/factorial.dir/factorial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factorial.dir/factorial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mcx/data_structure_algorithm/data_struct_al/recursive/factorial.cpp -o CMakeFiles/factorial.dir/factorial.cpp.s

# Object files for target factorial
factorial_OBJECTS = \
"CMakeFiles/factorial.dir/factorial.cpp.o"

# External object files for target factorial
factorial_EXTERNAL_OBJECTS =

factorial: CMakeFiles/factorial.dir/factorial.cpp.o
factorial: CMakeFiles/factorial.dir/build.make
factorial: CMakeFiles/factorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mcx/data_structure_algorithm/data_struct_al/recursive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable factorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/factorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/factorial.dir/build: factorial

.PHONY : CMakeFiles/factorial.dir/build

CMakeFiles/factorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/factorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/factorial.dir/clean

CMakeFiles/factorial.dir/depend:
	cd /home/mcx/data_structure_algorithm/data_struct_al/recursive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mcx/data_structure_algorithm/data_struct_al/recursive /home/mcx/data_structure_algorithm/data_struct_al/recursive /home/mcx/data_structure_algorithm/data_struct_al/recursive/build /home/mcx/data_structure_algorithm/data_struct_al/recursive/build /home/mcx/data_structure_algorithm/data_struct_al/recursive/build/CMakeFiles/factorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/factorial.dir/depend

