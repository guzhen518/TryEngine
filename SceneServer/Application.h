## --------------------------------------------------------------------
## 文件名:    CMakeLists.txt
## 内  容:    
## 说  明:    
## 创建日期:  2019年4月19日	
## 创建人:    
## 版权所有:  
## --------------------------------------------------------------------

set(SOURCES_files_Common_Files
    ../Common/Timer.h
	)

source_group("Common Files" FILES ${SOURCES_files_Common_Files})

set(SOURCES_Common_Files
	${SOURCES_files_Common_Files}
	)

set(SOURCES_files_source
	Application.h
	)

source_group("Source Files" FILES ${SOURCES_files_source})

set(SOURCES_file
      ${SOURCES_files_source}
    )

set(SOURCES_
		${SOURCES_file}
		${SOURCES_files_Common_Files}
	)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

#INCLUDE_DIRECTORIES(../extern/rapidxml-1.13)

SET(ProjectName SceneServer)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

if(WIN32)	
   SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
   SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
   SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
   SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
endif(WIN32)

#PROJECT(${ProjectName})
MESSAGE(STATUS "This is BINARY dir " ${${ProjectName}_BINARY_DIR}) 
MESSAGE(STATUS "This is SOURCE dir " ${${ProjectName}_SOURCE_DIR}) 
ADD_EXECUTABLE(${ProjectName} ${SOURCES_})
ADD_DEPENDENCIES(${ProjectName} libCommon)
TARGET_LINK_LIBRARIES(${ProjectName} libCommon)
##TARGET_LINK_LIBRARIES(${ProjectName} nedmalloc)

if(WIN32)
SET_TARGET_PROPERTIES(${ProjectName}  PROPERTIES   
     RUNTIME_OUTPUT_DIRECTORY  "${PROJECT_SOURCE_DIR}/bin/SceneServer") 
endif(WIN32)

if(NOT WIN32)
add_definitions(-D_PORT_VERSION -Wno-deprecated )
if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
add_definitions(-DNDEBUG)
endif(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
TARGET_LINK_LIBRARIES(${ProjectName} c stdc++ dl pthread uuid)
SET_TARGET_PROPERTIES(${ProjectName} PROPERTIES OUTPUT_NAME SceneServer.exe)
endif(NOT WIN32)
