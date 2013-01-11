 
#Set a variable with the name of the cpp source files of your application
SET(EXE_FILE_LIST test_tmsi.cpp)

SET(LIB_FILE_LIST amplifier.cpp
                amplifierdescription.cpp
                nexus.cpp
                tmsiamplifier.cpp
                tmsiamplifierdesc.cpp
                tmsichannels.cpp
                logger.cpp
    )
 
#Set a variable with the name of your application
SET(EXE_NAME tmsi_test)
SET(LIB_NAME tmsi)
 
#Create and link the library
ADD_LIBRARY (${LIB_NAME} ${LIB_FILE_LIST})
TARGET_LINK_LIBRARIES(${LIB_NAME} boost_date_time boost_program_options bluetooth)

#Create and link the executable
ADD_EXECUTABLE(${EXE_NAME} ${EXE_FILE_LIST})
TARGET_LINK_LIBRARIES(${EXE_NAME} ${LIB_NAME})
