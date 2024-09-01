cmake_minimum_required(VERSION 3.22)
project(Lab5)

set(CMAKE_C_COMPILER gcc)

get_filename_component(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE) #get absolute path to project root directory
set(BIN_DIR "${PROJECT_ROOT_DIR}/bin") #set bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}) #set bin directory as output directory

set(F_SOURCES ./src/api.c)
set(F_HEADERS ./inc/api.h)

set(C_SOURCES ./src/client.c)
set(C_HEADERS ./inc/client.h)

add_executable(api ${F_SOURCES} ${F_HEADERS})
add_executable(client ${C_SOURCES} ${C_HEADERS})

target_compile_options(api PRIVATE -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -g -pthread)
target_compile_options(client PRIVATE -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -g)

target_link_libraries(api PRIVATE ulfius jansson curl orcania)