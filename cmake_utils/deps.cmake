#BOOST
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
    MESSAGE("Boost Found at ${Boost_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ELSE(Boost_FOUND)
    MESSAGE(FATAL_ERROR "Boost not founde. BUIT IT IS REQUIRED")
ENDIF()

INCLUDE (${TMSI_CMAKE_MODULE_PATH}/CheckFunctionExists.cmake)
	MESSAGE(STATUS "Checking time functions")
	check_function_exists(gettimeofday HAVE_GETTIMEOFDAY)
	check_function_exists(clock_gettime HAVE_CLOCK_GETTIME)






