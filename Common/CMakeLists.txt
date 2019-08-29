## --------------------------------------------------------------------
## 文件名:    CMakeLists.txt
## 内  容:    
## 说  明:    
## 创建日期:  
## 创建人:    
## 版权所有:  
## --------------------------------------------------------------------

    set(SOURCES_files_SourceFiles
		Debug.cpp
		mempool.cpp
		memsafety.cpp
		Timer.cpp
		TryLinkList.cpp
		../Net/SocketOpt.cpp
		
    )
    source_group("Source Files" FILES ${SOURCES_files_SourceFiles})

    set(SOURCES_SourceFiles
      ${SOURCES_files_SourceFiles}
    )

    set(SOURCES_files_HeadFiles
		Macros.h
		Debug.h
		mempool.h
		memsafety.h
		Timer.h
		TryLinkList.h
		../Net/SocketOpt.h
		
    )
    source_group("Head Files" FILES ${SOURCES_files_HeadFiles})

    set(SOURCES_HeadFiles
      ${SOURCES_files_HeadFiles}
    )

  set(SOURCES_
    ${SOURCES_SourceFiles}
    ${SOURCES_HeadFiles}
  )

  if(WIN32)	
   SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
   SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
   SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
   SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
endif(WIN32)

SET(ProjectName libCommon)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

ADD_LIBRARY(${ProjectName} STATIC ${SOURCES_})

if(NOT WIN32)
add_definitions(-D_PORT_VERSION -Wno-deprecated  -fPIC)
if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
add_definitions(-DNDEBUG)
endif(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
endif(NOT WIN32)
