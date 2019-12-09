## --------------------------------------------------------------------
## 文件名:    CMakeLists.txt
## 内  容:    public目录
## 说  明:    libPublic工程管理文件
## 创建日期:  2012年11月22日	
## 创建人:    
## 版权所有:  
## --------------------------------------------------------------------

    set(SOURCES_files_SourceFiles
		AoiEntity.cpp
		AoiManager.cpp
		GameScene.cpp
		SceneEntity.cpp
		SceneManager.cpp
		SceneServer.cpp
		
		
    )
    source_group("Source Files" FILES ${SOURCES_files_SourceFiles})

    set(SOURCES_SourceFiles
      ${SOURCES_files_SourceFiles}
    )

    set(SOURCES_files_HeadFiles
		Application.h
		AoiEntity.h
		AoiManager.h
		GameScene.h
		SceneEntity.h
		SceneManager.h
		../Common/TryLog.h
		
		
    )
    source_group("Head Files" FILES ${SOURCES_files_HeadFiles})

    set(SOURCES_HeadFiles
      ${SOURCES_files_HeadFiles}
    )

  set(SOURCES_
    ${SOURCES_SourceFiles}
    ${SOURCES_HeadFiles}
  )
  

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib) 
INCLUDE_DIRECTORIES(../extern/log4cplus-1.2.1/include)

SET(ProjectName SceneServer)
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
ADD_DEPENDENCIES(${ProjectName} log4cplusSD)
TARGET_LINK_LIBRARIES(${ProjectName} log4cplusSD)

if(WIN32)
SET_TARGET_PROPERTIES(${ProjectName}  PROPERTIES   
     RUNTIME_OUTPUT_DIRECTORY  "${PROJECT_SOURCE_DIR}/bin/SceneServer") 
endif(WIN32)


if(NOT WIN32)
add_definitions(-D_PORT_VERSION -Wno-deprecated  -fPIC)
if(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
add_definitions(-DNDEBUG)
endif(CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE STREQUAL "Release" OR "MinSizeRel" OR "RelWithDebInfo")
TARGET_LINK_LIBRARIES(${ProjectName} c stdc++ dl pthread uuid)
SET_TARGET_PROPERTIES(${ProjectName} PROPERTIES OUTPUT_NAME lobbysvr.exe)

endif(NOT WIN32)
