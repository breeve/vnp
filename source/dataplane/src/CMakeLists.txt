cmake_minimum_required(VERSION 3.16)

project(sdn)

set(CMAKE_C_FLAGS "-g -Wall")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/dev/bin)

include_directories(${PROJECT_SOURCE_DIR}/source/dataplane/src/include)

add_executable(dataplane $(SRC_LIST))