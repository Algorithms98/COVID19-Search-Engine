cmake_minimum_required(VERSION 3.10)
project(CS2341-SearchEngine)
set (EXE_NAME SearchEngine)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "")
set (input02 "")
set (input03 "")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp AVLIndex.h AVLIndex.cpp AVLIndex.cpp AVLTree.h DocumentParser.cpp DocumentParser.h HashIndex.cpp HashIndex.h HashTable.h IndexHandler.cpp IndexHandler.h IndexInterface.h json.hpp parser.hpp Porter2_Stemmer.cpp Porter2_Stemmer.h QueryParser.cpp QueryParser.h SearchEngine.cpp SearchEngine.h StopWords.cpp StopWords.h UserInterface.cpp UserInterface.h Words.cpp Words.h)
