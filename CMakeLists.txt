cmake_minimum_required(VERSION 3.10.2)
project(tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -pedantic -lm -std=c++11")
set(INC_DIR ${CMAKE_SOURCE_DIR}/circularBuffer/inc ${CMAKE_SOURCE_DIR}/tests/inc)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/circularBuffer/src ${CMAKE_SOURCE_DIR}/tests/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

file(GLOB H_FILES ${INC_DIR}/*.h)
file(GLOB CPP_FILES ${MAIN_DIR}/*.cpp ${SRC_DIR}/*.cpp)

set(SOURCES ${H_FILES} ${CPP_FILES})

include_directories(${INC_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

add_custom_target(run ./${PROJECT_NAME})
add_custom_target(cleanall rm -r ${PROJECT_NAME}  CMakeCache.txt  CMakeFiles  cmake_install.cmake Makefile)
