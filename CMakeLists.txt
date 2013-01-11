#Minimum version required for CMake
cmake_minimum_required (VERSION 2.6)
 
#Name of the project
project (tmsi)
 
#Compile in Debug Mode. Allows to make debug.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
SET(CMAKE_BUILD_TYPE "debugfull" )
 
#Set a variable with the directory path.
SET(TMSI_TRUNK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
#Set a variable with the path of the application.
SET(EXECUTABLE_OUTPUT_PATH ${OOM_TRUNK_DIR}/bin)
 
#In Linux and Mac OS/X the Path is /usr/include/ooml
#INCLUDE_DIRECTORIES("/usr/include")

ADD_SUBDIRECTORY(src)
