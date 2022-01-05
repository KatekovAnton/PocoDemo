cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME_HOST PocoDemoCommonHost)
set(PROJECT_NAME_NET PocoDemoCommonNet)



IF(APPLE)
    SET (PROJECT_OS_MACOS TRUE BOOL INTERNAL)
    add_definitions(-DPROJECTN_TARGET_OS_MAC )
ENDIF (APPLE)
IF(WIN32)
    SET (PROJECT_OS_WIN32 TRUE BOOL INTERNAL)
    add_definitions(-DPROJECTN_TARGET_OS_WIN )
ENDIF (WIN32)
if(UNIX AND NOT APPLE) 
    SET (PROJECT_OS_LINUX TRUE BOOL INTERNAL)
    add_definitions(-DPROJECTN_TARGET_OS_LINUX )
ENDIF (UNIX AND NOT APPLE)



project(${PROJECT_NAME_HOST} C CXX)
project(${PROJECT_NAME_NET} C CXX)



include_directories("${PROJECT_SOURCE_DIR}")



file(GLOB_RECURSE PROJECT_SOURCES 
    ${PROJECT_SOURCE_DIR}/*.*
)



if(CMAKE_GENERATOR STREQUAL Xcode)

    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14")
    
    add_executable(${PROJECT_NAME_HOST} 
        ${PROJECT_SOURCES})

    add_executable(${PROJECT_NAME_NET} 
        ${PROJECT_SOURCES})
 
else ()

    add_executable(${PROJECT_NAME_HOST} ${PROJECT_SOURCES})

    add_executable(${PROJECT_NAME_NET} ${PROJECT_SOURCES})
    
endif()



target_compile_definitions(${PROJECT_NAME_HOST} PRIVATE TARGET_HOST)



if (PROJECT_OS_MACOS)

    list(APPEND SRE_INCLUDE_DIRS /System/Library/Frameworks)
    
    target_link_libraries(${PROJECT_NAME_HOST} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME_HOST} "-lc")

    target_link_libraries(${PROJECT_NAME_NET} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME_NET} "-lc")
    
endif()



target_link_libraries(${PROJECT_NAME_HOST} Poco::Net Poco::Util Poco::JSON)
target_link_libraries(${PROJECT_NAME_NET} Poco::Net Poco::Util Poco::JSON)
