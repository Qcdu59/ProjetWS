# Build our application
include_directories(${CMAKE_CURRENT_LIST_DIR})
file(GLOB_RECURSE HELLO_WORLD_SOURCE_FILES *.cpp)
 
add_executable(hello_world ${HELLO_WORLD_SOURCE_FILES})
target_link_libraries(hello_world
    ${LIB_BOOSTER}
    ${LIB_CPPCMS})
