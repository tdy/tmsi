# CMakeLists.txt for tmsi linux driver
# @author Alberto Valero-Gómez
# @mail alberto.valero.gomez@gmail.com
# @date 11 Jan 2013

#Minimum version required for CMake
cmake_minimum_required (VERSION 2.6)
 
#Name of the project
project (tmsi)
 
#Compile in Debug Mode. Allows to make debug.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
SET(CMAKE_BUILD_TYPE "debugfull" )
 
#Set a variable with the directory path.
SET(TMSI_TRUNK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(TMSI_CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_utils")
 
#Set a variable with the path of the application.
SET(EXECUTABLE_OUTPUT_PATH ${TMSI_TRUNK_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${TMSI_TRUNK_DIR}/lib)

# Find and configure switches for external libraries and applications
INCLUDE(${TMSI_CMAKE_MODULE_PATH}/deps.cmake)

# Creation of config.h
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.cmake" "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h")


INCLUDE_DIRECTORIES(src)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(src/tests)
