cmake_minimum_required (VERSION 2.8.8)
project (hello_world)
 
# We want binaries be compiled at the root of build folder
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
# We want always all warnings but no sign comparison ones. :D
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-sign-compare")
 
# Find booster
find_library(LIB_BOOSTER booster)
find_path(INC_BOOSTER booster/config.h)
include_directories(${INC_BOOSTER})
 
# Find cppcms
find_library(LIB_CPPCMS cppcms)
find_path(INC_CPPCMS cppcms/config.h)
include_directories(${INC_CPPCMS})
 
add_subdirectory(src)
