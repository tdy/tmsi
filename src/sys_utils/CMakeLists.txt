#Set a variable with the name of the cpp source files of your application
SET(LIB_FILE_LIST time.cpp)
 
#Set a variable with the name of your application
SET(LIB_NAME sys_utils)
 
#Create and link the library
ADD_LIBRARY (${LIB_NAME} ${LIB_FILE_LIST})
#TARGET_LINK_LIBRARIES(${LIB_NAME})
