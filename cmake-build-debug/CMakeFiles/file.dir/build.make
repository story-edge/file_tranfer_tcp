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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Pro/C/file

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Pro/C/file/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/file.dir/flags.make

CMakeFiles/file.dir/main.c.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/file.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file.dir/main.c.o   -c /mnt/d/Pro/C/file/main.c

CMakeFiles/file.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Pro/C/file/main.c > CMakeFiles/file.dir/main.c.i

CMakeFiles/file.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Pro/C/file/main.c -o CMakeFiles/file.dir/main.c.s

CMakeFiles/file.dir/tcp_socket.c.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/tcp_socket.c.o: ../tcp_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/file.dir/tcp_socket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file.dir/tcp_socket.c.o   -c /mnt/d/Pro/C/file/tcp_socket.c

CMakeFiles/file.dir/tcp_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file.dir/tcp_socket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Pro/C/file/tcp_socket.c > CMakeFiles/file.dir/tcp_socket.c.i

CMakeFiles/file.dir/tcp_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file.dir/tcp_socket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Pro/C/file/tcp_socket.c -o CMakeFiles/file.dir/tcp_socket.c.s

CMakeFiles/file.dir/server.c.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/file.dir/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file.dir/server.c.o   -c /mnt/d/Pro/C/file/server.c

CMakeFiles/file.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file.dir/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Pro/C/file/server.c > CMakeFiles/file.dir/server.c.i

CMakeFiles/file.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file.dir/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Pro/C/file/server.c -o CMakeFiles/file.dir/server.c.s

CMakeFiles/file.dir/client.c.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/file.dir/client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file.dir/client.c.o   -c /mnt/d/Pro/C/file/client.c

CMakeFiles/file.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file.dir/client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Pro/C/file/client.c > CMakeFiles/file.dir/client.c.i

CMakeFiles/file.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file.dir/client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Pro/C/file/client.c -o CMakeFiles/file.dir/client.c.s

CMakeFiles/file.dir/file_transfer.c.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/file_transfer.c.o: ../file_transfer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/file.dir/file_transfer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file.dir/file_transfer.c.o   -c /mnt/d/Pro/C/file/file_transfer.c

CMakeFiles/file.dir/file_transfer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file.dir/file_transfer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Pro/C/file/file_transfer.c > CMakeFiles/file.dir/file_transfer.c.i

CMakeFiles/file.dir/file_transfer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file.dir/file_transfer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Pro/C/file/file_transfer.c -o CMakeFiles/file.dir/file_transfer.c.s

# Object files for target file
file_OBJECTS = \
"CMakeFiles/file.dir/main.c.o" \
"CMakeFiles/file.dir/tcp_socket.c.o" \
"CMakeFiles/file.dir/server.c.o" \
"CMakeFiles/file.dir/client.c.o" \
"CMakeFiles/file.dir/file_transfer.c.o"

# External object files for target file
file_EXTERNAL_OBJECTS =

file: CMakeFiles/file.dir/main.c.o
file: CMakeFiles/file.dir/tcp_socket.c.o
file: CMakeFiles/file.dir/server.c.o
file: CMakeFiles/file.dir/client.c.o
file: CMakeFiles/file.dir/file_transfer.c.o
file: CMakeFiles/file.dir/build.make
file: CMakeFiles/file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/file.dir/build: file

.PHONY : CMakeFiles/file.dir/build

CMakeFiles/file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/file.dir/clean

CMakeFiles/file.dir/depend:
	cd /mnt/d/Pro/C/file/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Pro/C/file /mnt/d/Pro/C/file /mnt/d/Pro/C/file/cmake-build-debug /mnt/d/Pro/C/file/cmake-build-debug /mnt/d/Pro/C/file/cmake-build-debug/CMakeFiles/file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/file.dir/depend

