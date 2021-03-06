cmake_minimum_required (VERSION 3.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

if(WIN32) 
add_definitions(/DWINVER=0x0600 /D_WIN32_WINNT=0x0600)
endif()

add_definitions(/DINTERCEPT_HOST_DLL=1)

if (NOT CMAKE_BUILD_TYPE AND CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "No build type selected, default to Debug")
	set(CMAKE_BUILD_TYPE "Debug")
endif()

option(DEVEL "DEVEL" ON)
option(USE_STATIC_LINKING "USE_STATIC_LINKING" ON)


if(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "-std=c++11 -march=i686 -m32 -O2 -s -fPIC -fpermissive")
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
	set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
else()
	set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MTd /Zi /Ob0 /Od /RTC1 /EHsc")
	set(CMAKE_CXX_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /D /EHsc NDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE       "/MT /O2 /Ob2 /D /EHsc NDEBUG")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /O2 /Ob1 /D /EHsc NDEBUG")
endif()
include_directories("common")
include_directories("controller")
include_directories("loader")
include_directories("invoker")
include_directories("extensions")
include_directories("../client/headers")
include_directories("intercept_dll")


if(DEVEL)
    add_definitions(-DDEVEL)
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR}/common)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/controller)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/loader)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/invoker)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/extensions)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/intercept_dll)


set(GLOBAL_SOURCES ${GLOBAL_RC})


add_subdirectory(common)
add_subdirectory(controller)
add_subdirectory(loader)
add_subdirectory(invoker)
add_subdirectory(extensions)
add_subdirectory(intercept_dll)



message("Build Type: ${CMAKE_BUILD_TYPE}")