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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SearchEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SearchEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SearchEngine.dir/flags.make

CMakeFiles/SearchEngine.dir/main.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SearchEngine.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/main.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/main.cpp

CMakeFiles/SearchEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/main.cpp > CMakeFiles/SearchEngine.dir/main.cpp.i

CMakeFiles/SearchEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/main.cpp -o CMakeFiles/SearchEngine.dir/main.cpp.s

CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o: ../AVLIndex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/AVLIndex.cpp

CMakeFiles/SearchEngine.dir/AVLIndex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/AVLIndex.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/AVLIndex.cpp > CMakeFiles/SearchEngine.dir/AVLIndex.cpp.i

CMakeFiles/SearchEngine.dir/AVLIndex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/AVLIndex.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/AVLIndex.cpp -o CMakeFiles/SearchEngine.dir/AVLIndex.cpp.s

CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o: ../DocumentParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/DocumentParser.cpp

CMakeFiles/SearchEngine.dir/DocumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/DocumentParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/DocumentParser.cpp > CMakeFiles/SearchEngine.dir/DocumentParser.cpp.i

CMakeFiles/SearchEngine.dir/DocumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/DocumentParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/DocumentParser.cpp -o CMakeFiles/SearchEngine.dir/DocumentParser.cpp.s

CMakeFiles/SearchEngine.dir/HashIndex.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/HashIndex.cpp.o: ../HashIndex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SearchEngine.dir/HashIndex.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/HashIndex.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/HashIndex.cpp

CMakeFiles/SearchEngine.dir/HashIndex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/HashIndex.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/HashIndex.cpp > CMakeFiles/SearchEngine.dir/HashIndex.cpp.i

CMakeFiles/SearchEngine.dir/HashIndex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/HashIndex.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/HashIndex.cpp -o CMakeFiles/SearchEngine.dir/HashIndex.cpp.s

CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o: ../IndexHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/IndexHandler.cpp

CMakeFiles/SearchEngine.dir/IndexHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/IndexHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/IndexHandler.cpp > CMakeFiles/SearchEngine.dir/IndexHandler.cpp.i

CMakeFiles/SearchEngine.dir/IndexHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/IndexHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/IndexHandler.cpp -o CMakeFiles/SearchEngine.dir/IndexHandler.cpp.s

CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o: ../Porter2_Stemmer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Porter2_Stemmer.cpp

CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Porter2_Stemmer.cpp > CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.i

CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Porter2_Stemmer.cpp -o CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.s

CMakeFiles/SearchEngine.dir/QueryParser.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/QueryParser.cpp.o: ../QueryParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SearchEngine.dir/QueryParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/QueryParser.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/QueryParser.cpp

CMakeFiles/SearchEngine.dir/QueryParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/QueryParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/QueryParser.cpp > CMakeFiles/SearchEngine.dir/QueryParser.cpp.i

CMakeFiles/SearchEngine.dir/QueryParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/QueryParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/QueryParser.cpp -o CMakeFiles/SearchEngine.dir/QueryParser.cpp.s

CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o: ../SearchEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/SearchEngine.cpp

CMakeFiles/SearchEngine.dir/SearchEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/SearchEngine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/SearchEngine.cpp > CMakeFiles/SearchEngine.dir/SearchEngine.cpp.i

CMakeFiles/SearchEngine.dir/SearchEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/SearchEngine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/SearchEngine.cpp -o CMakeFiles/SearchEngine.dir/SearchEngine.cpp.s

CMakeFiles/SearchEngine.dir/StopWords.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/StopWords.cpp.o: ../StopWords.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SearchEngine.dir/StopWords.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/StopWords.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/StopWords.cpp

CMakeFiles/SearchEngine.dir/StopWords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/StopWords.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/StopWords.cpp > CMakeFiles/SearchEngine.dir/StopWords.cpp.i

CMakeFiles/SearchEngine.dir/StopWords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/StopWords.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/StopWords.cpp -o CMakeFiles/SearchEngine.dir/StopWords.cpp.s

CMakeFiles/SearchEngine.dir/UserInterface.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/UserInterface.cpp.o: ../UserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SearchEngine.dir/UserInterface.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/UserInterface.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/UserInterface.cpp

CMakeFiles/SearchEngine.dir/UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/UserInterface.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/UserInterface.cpp > CMakeFiles/SearchEngine.dir/UserInterface.cpp.i

CMakeFiles/SearchEngine.dir/UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/UserInterface.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/UserInterface.cpp -o CMakeFiles/SearchEngine.dir/UserInterface.cpp.s

CMakeFiles/SearchEngine.dir/Words.cpp.o: CMakeFiles/SearchEngine.dir/flags.make
CMakeFiles/SearchEngine.dir/Words.cpp.o: ../Words.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SearchEngine.dir/Words.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchEngine.dir/Words.cpp.o -c /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Words.cpp

CMakeFiles/SearchEngine.dir/Words.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchEngine.dir/Words.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Words.cpp > CMakeFiles/SearchEngine.dir/Words.cpp.i

CMakeFiles/SearchEngine.dir/Words.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchEngine.dir/Words.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/Words.cpp -o CMakeFiles/SearchEngine.dir/Words.cpp.s

# Object files for target SearchEngine
SearchEngine_OBJECTS = \
"CMakeFiles/SearchEngine.dir/main.cpp.o" \
"CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o" \
"CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o" \
"CMakeFiles/SearchEngine.dir/HashIndex.cpp.o" \
"CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o" \
"CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o" \
"CMakeFiles/SearchEngine.dir/QueryParser.cpp.o" \
"CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o" \
"CMakeFiles/SearchEngine.dir/StopWords.cpp.o" \
"CMakeFiles/SearchEngine.dir/UserInterface.cpp.o" \
"CMakeFiles/SearchEngine.dir/Words.cpp.o"

# External object files for target SearchEngine
SearchEngine_EXTERNAL_OBJECTS =

SearchEngine: CMakeFiles/SearchEngine.dir/main.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/AVLIndex.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/DocumentParser.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/HashIndex.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/IndexHandler.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/Porter2_Stemmer.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/QueryParser.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/SearchEngine.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/StopWords.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/UserInterface.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/Words.cpp.o
SearchEngine: CMakeFiles/SearchEngine.dir/build.make
SearchEngine: CMakeFiles/SearchEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable SearchEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SearchEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SearchEngine.dir/build: SearchEngine

.PHONY : CMakeFiles/SearchEngine.dir/build

CMakeFiles/SearchEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SearchEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SearchEngine.dir/clean

CMakeFiles/SearchEngine.dir/depend:
	cd /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98 /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98 /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug /Users/princendhlovu/Desktop/CS2341-SearchEngine-Algorithms98/cmake-build-debug/CMakeFiles/SearchEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SearchEngine.dir/depend
