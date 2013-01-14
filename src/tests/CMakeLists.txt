 
#Set a variable with the name of the cpp source files of your application
SET(EXE_FILE_LIST_0 test_tmsi_0.cpp)
SET(EXE_FILE_LIST_1 test_tmsi_1.cpp)
 
#Set a variable with the name of your application
SET(EXE_NAME tmsi_test_1)
SET(LIB_NAME tmsi)

#Create and link the executable
ADD_EXECUTABLE(tmsi_test_0 ${EXE_FILE_LIST_0})
TARGET_LINK_LIBRARIES(tmsi_test_0 tmsi)

ADD_EXECUTABLE(tmsi_test_1 ${EXE_FILE_LIST_1})
TARGET_LINK_LIBRARIES(tmsi_test_1 tmsi)
