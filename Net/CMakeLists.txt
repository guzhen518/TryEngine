## --------------------------------------------------------------------
## 文件名:    CMakeLists.txt
## 内  容:    tools目录
## 说  明:    libTools工程管理文件
## 创建日期:  2012年8月22日	
## 创建人:    
## 版权所有:  
## --------------------------------------------------------------------

###################################################################################
    set(SOURCES_files_SourceFiles
		CAcceptor.h
		CConnector.h
		SocketOpt.h
		TcpServer.h
		EventLoop.h
    )
    source_group("Head Files" FILES ${SOURCES_files_SourceFiles})

    set(SOURCES_SourceFiles
      ${SOURCES_files_SourceFiles}
    )


####################################################################################

    set(SOURCES_files_HeadFiles
		CAcceptor.cpp
		CConnector.cpp
		SocketOpt.cpp
		TcpServer.cpp
		EventLoop.cpp
    )
    source_group("Source Files" FILES ${SOURCES_files_HeadFiles})

    set(SOURCES_HeadFiles
      ${SOURCES_files_HeadFiles}
    )

  set(SOURCES_
    ${SOURCES_SourceFiles}
    ${SOURCES_HeadFiles}
  )

SET(ProjectName libNet)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

ADD_LIBRARY(${ProjectName} STATIC ${SOURCES_})

if(WIN32)	
   SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
   SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
   SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
   SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
endif(WIN32)

if(WIN32)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else(WIN32)
add_definitions(-D_PORT_VERSION -Wno-deprecated  -fPIC)
if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
add_definitions(-DNDEBUG)
endif(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
endif(WIN32)
