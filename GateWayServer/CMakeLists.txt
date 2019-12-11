## --------------------------------------------------------------------
## 文件名:    CMakeLists.txt
## 内  容:    public目录
## 说  明:    libPublic工程管理文件
## 创建日期:  2012年11月22日	
## 创建人:    
## 版权所有:  
## --------------------------------------------------------------------


################################# Source ###############################################
	set(SOURCES_files_SourceFiles
		GateWayServer.cpp
		
		
    )
    source_group("Source Files" FILES ${SOURCES_files_SourceFiles})

    set(SOURCES_SourceFiles
      ${SOURCES_files_SourceFiles}
    )
####################################NET##############################################
	set(SOURCES_files_NetFiles
		../Net/TcpServer.h
		
		
    )
    source_group("Net" FILES ${SOURCES_files_NetFiles})

    set(SOURCES_NetFiles
      ${SOURCES_files_NetFiles}
    )
	
  set(SOURCES_
    ${SOURCES_SourceFiles}
    ${SOURCES_NetFiles}
  )
  
  
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib) 

SET(ProjectName GateWayServer)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})	#设置输出路径

  if(WIN32)	
   SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
   SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
   SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
   SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
endif(WIN32)

MESSAGE(STATUS "This is BINARY dir " ${${ProjectName}_BINARY_DIR}) 
MESSAGE(STATUS "This is SOURCE dir " ${${ProjectName}_SOURCE_DIR}) 

ADD_EXECUTABLE(${ProjectName} ${SOURCES_})


if(NOT WIN32)
add_definitions(-D_PORT_VERSION -Wno-deprecated  -fPIC)
if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
add_definitions(-DNDEBUG)
endif(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
TARGET_LINK_LIBRARIES(${ProjectName} c stdc++ dl pthread uuid)
SET_TARGET_PROPERTIES(${ProjectName} PROPERTIES OUTPUT_NAME GateWayServer.exe)

endif(NOT WIN32)
