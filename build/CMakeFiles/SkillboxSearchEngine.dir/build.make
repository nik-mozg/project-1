# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\develop\40

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\develop\40\build

# Include any dependencies generated for this target.
include CMakeFiles/SkillboxSearchEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SkillboxSearchEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SkillboxSearchEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SkillboxSearchEngine.dir/flags.make

CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj: CMakeFiles/SkillboxSearchEngine.dir/flags.make
CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj: CMakeFiles/SkillboxSearchEngine.dir/includes_CXX.rsp
CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj: C:/develop/40/src/main.cpp
CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj: CMakeFiles/SkillboxSearchEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\40\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj -MF CMakeFiles\SkillboxSearchEngine.dir\src\main.cpp.obj.d -o CMakeFiles\SkillboxSearchEngine.dir\src\main.cpp.obj -c C:\develop\40\src\main.cpp

CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\40\src\main.cpp > CMakeFiles\SkillboxSearchEngine.dir\src\main.cpp.i

CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\40\src\main.cpp -o CMakeFiles\SkillboxSearchEngine.dir\src\main.cpp.s

# Object files for target SkillboxSearchEngine
SkillboxSearchEngine_OBJECTS = \
"CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj"

# External object files for target SkillboxSearchEngine
SkillboxSearchEngine_EXTERNAL_OBJECTS =

SkillboxSearchEngine.exe: CMakeFiles/SkillboxSearchEngine.dir/src/main.cpp.obj
SkillboxSearchEngine.exe: CMakeFiles/SkillboxSearchEngine.dir/build.make
SkillboxSearchEngine.exe: libSkillboxSearchEngineLib.a
SkillboxSearchEngine.exe: CMakeFiles/SkillboxSearchEngine.dir/linkLibs.rsp
SkillboxSearchEngine.exe: CMakeFiles/SkillboxSearchEngine.dir/objects1.rsp
SkillboxSearchEngine.exe: CMakeFiles/SkillboxSearchEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\develop\40\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SkillboxSearchEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SkillboxSearchEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SkillboxSearchEngine.dir/build: SkillboxSearchEngine.exe
.PHONY : CMakeFiles/SkillboxSearchEngine.dir/build

CMakeFiles/SkillboxSearchEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SkillboxSearchEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SkillboxSearchEngine.dir/clean

CMakeFiles/SkillboxSearchEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\develop\40 C:\develop\40 C:\develop\40\build C:\develop\40\build C:\develop\40\build\CMakeFiles\SkillboxSearchEngine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SkillboxSearchEngine.dir/depend

