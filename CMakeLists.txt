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
SET(EXECUTABLE_OUTPUT_PATH ${TMSI_TRUNK_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${TMSI_TRUNK_DIR}/lib)
 
#In Linux and Mac OS/X the Path is /usr/include/ooml
#INCLUDE_DIRECTORIES("/usr/include")

#FIND REQUIRED LIBRARIES
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
    MESSAGE("Boost Found at ${Boost_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ELSE(Boost_FOUND)
    MESSAGE(FATAL_ERROR "Boost not founde. BUIT IT IS REQUIRED")
ENDIF()

ADD_SUBDIRECTORY(src)
