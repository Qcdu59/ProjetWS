# Build our application
include_directories(${CMAKE_CURRENT_LIST_DIR})
file(GLOB_RECURSE HELLO_WORLD_SOURCE_FILES *.cpp)
 
execute_process(COMMAND mysql_config --cflags
    OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND mysql_config --libs
    OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
 
add_executable(hello_world ${HELLO_WORLD_SOURCE_FILES})
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_MYSQL_COMPILE_FLAGS}")
target_link_libraries(hello_world
    ${LIB_BOOSTER}
    ${LIB_CPPCMS}
    ${MYSQL_LIBS})
