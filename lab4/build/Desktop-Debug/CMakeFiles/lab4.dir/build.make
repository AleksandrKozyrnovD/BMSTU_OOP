# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aleksandr/Desktop/bmstu/oop/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.dir/flags.make

lab4_autogen/timestamp: /usr/lib/qt6/moc
lab4_autogen/timestamp: /usr/lib/qt6/uic
lab4_autogen/timestamp: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target lab4"
	/usr/bin/cmake -E cmake_autogen /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles/lab4_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/lab4_autogen/timestamp

CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o: lab4_autogen/mocs_compilation.cpp
CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o -MF CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/lab4_autogen/mocs_compilation.cpp

CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/lab4_autogen/mocs_compilation.cpp > CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.i

CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/lab4_autogen/mocs_compilation.cpp -o CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.s

CMakeFiles/lab4.dir/main.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/main.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/main.cpp
CMakeFiles/lab4.dir/main.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab4.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/main.cpp.o -MF CMakeFiles/lab4.dir/main.cpp.o.d -o CMakeFiles/lab4.dir/main.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/main.cpp

CMakeFiles/lab4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/main.cpp > CMakeFiles/lab4.dir/main.cpp.i

CMakeFiles/lab4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/main.cpp -o CMakeFiles/lab4.dir/main.cpp.s

CMakeFiles/lab4.dir/mainwindow.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/mainwindow.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/mainwindow.cpp
CMakeFiles/lab4.dir/mainwindow.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab4.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/mainwindow.cpp.o -MF CMakeFiles/lab4.dir/mainwindow.cpp.o.d -o CMakeFiles/lab4.dir/mainwindow.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/mainwindow.cpp

CMakeFiles/lab4.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/mainwindow.cpp > CMakeFiles/lab4.dir/mainwindow.cpp.i

CMakeFiles/lab4.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/mainwindow.cpp -o CMakeFiles/lab4.dir/mainwindow.cpp.s

CMakeFiles/lab4.dir/cabin.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/cabin.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/cabin.cpp
CMakeFiles/lab4.dir/cabin.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab4.dir/cabin.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/cabin.cpp.o -MF CMakeFiles/lab4.dir/cabin.cpp.o.d -o CMakeFiles/lab4.dir/cabin.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/cabin.cpp

CMakeFiles/lab4.dir/cabin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/cabin.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/cabin.cpp > CMakeFiles/lab4.dir/cabin.cpp.i

CMakeFiles/lab4.dir/cabin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/cabin.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/cabin.cpp -o CMakeFiles/lab4.dir/cabin.cpp.s

CMakeFiles/lab4.dir/controller.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/controller.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/controller.cpp
CMakeFiles/lab4.dir/controller.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab4.dir/controller.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/controller.cpp.o -MF CMakeFiles/lab4.dir/controller.cpp.o.d -o CMakeFiles/lab4.dir/controller.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/controller.cpp

CMakeFiles/lab4.dir/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/controller.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/controller.cpp > CMakeFiles/lab4.dir/controller.cpp.i

CMakeFiles/lab4.dir/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/controller.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/controller.cpp -o CMakeFiles/lab4.dir/controller.cpp.s

CMakeFiles/lab4.dir/doors.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/doors.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/doors.cpp
CMakeFiles/lab4.dir/doors.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab4.dir/doors.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/doors.cpp.o -MF CMakeFiles/lab4.dir/doors.cpp.o.d -o CMakeFiles/lab4.dir/doors.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/doors.cpp

CMakeFiles/lab4.dir/doors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/doors.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/doors.cpp > CMakeFiles/lab4.dir/doors.cpp.i

CMakeFiles/lab4.dir/doors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/doors.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/doors.cpp -o CMakeFiles/lab4.dir/doors.cpp.s

CMakeFiles/lab4.dir/lift.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/lift.cpp.o: /home/aleksandr/Desktop/bmstu/oop/lab4/lift.cpp
CMakeFiles/lab4.dir/lift.cpp.o: CMakeFiles/lab4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lab4.dir/lift.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab4.dir/lift.cpp.o -MF CMakeFiles/lab4.dir/lift.cpp.o.d -o CMakeFiles/lab4.dir/lift.cpp.o -c /home/aleksandr/Desktop/bmstu/oop/lab4/lift.cpp

CMakeFiles/lab4.dir/lift.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab4.dir/lift.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksandr/Desktop/bmstu/oop/lab4/lift.cpp > CMakeFiles/lab4.dir/lift.cpp.i

CMakeFiles/lab4.dir/lift.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/lift.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksandr/Desktop/bmstu/oop/lab4/lift.cpp -o CMakeFiles/lab4.dir/lift.cpp.s

# Object files for target lab4
lab4_OBJECTS = \
"CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/lab4.dir/main.cpp.o" \
"CMakeFiles/lab4.dir/mainwindow.cpp.o" \
"CMakeFiles/lab4.dir/cabin.cpp.o" \
"CMakeFiles/lab4.dir/controller.cpp.o" \
"CMakeFiles/lab4.dir/doors.cpp.o" \
"CMakeFiles/lab4.dir/lift.cpp.o"

# External object files for target lab4
lab4_EXTERNAL_OBJECTS =

lab4: CMakeFiles/lab4.dir/lab4_autogen/mocs_compilation.cpp.o
lab4: CMakeFiles/lab4.dir/main.cpp.o
lab4: CMakeFiles/lab4.dir/mainwindow.cpp.o
lab4: CMakeFiles/lab4.dir/cabin.cpp.o
lab4: CMakeFiles/lab4.dir/controller.cpp.o
lab4: CMakeFiles/lab4.dir/doors.cpp.o
lab4: CMakeFiles/lab4.dir/lift.cpp.o
lab4: CMakeFiles/lab4.dir/build.make
lab4: /usr/lib/libQt6Widgets.so.6.7.0
lab4: /usr/lib/libQt6Gui.so.6.7.0
lab4: /usr/lib/libQt6Core.so.6.7.0
lab4: /usr/lib/libGLX.so
lab4: /usr/lib/libOpenGL.so
lab4: CMakeFiles/lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.dir/build: lab4
.PHONY : CMakeFiles/lab4.dir/build

CMakeFiles/lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4.dir/clean

CMakeFiles/lab4.dir/depend: lab4_autogen/timestamp
	cd /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aleksandr/Desktop/bmstu/oop/lab4 /home/aleksandr/Desktop/bmstu/oop/lab4 /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug /home/aleksandr/Desktop/bmstu/oop/lab4/build/Desktop-Debug/CMakeFiles/lab4.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab4.dir/depend

