
cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

# set and check compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall")

set(PROJECT_NAME moment)
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)

project (${PROJECT_NAME} CXX)

# The version number.
set (VERSION 1.0.0)

include_directories ("${PROJECT_SOURCE_DIR}/include")
#include_directories ("${PROJECT_SOURCE_DIR}/src")
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} "src/moment.cpp" )
add_executable (main main.cpp)
# install(TARGETS ${PROJECT_NAME} DESTINATION "${PROJECT_SOURCE_DIR}/bin")
# install(TARGETS main DESTINATION "${PROJECT_SOURCE_DIR}/bin")

#---- TEST ----
enable_testing()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

# link gtest
find_package(GTest REQUIRED)
if (GTEST_FOUND)
  include_directories(${GTEST_INCLUDE_DIRS})
  target_link_libraries (${PROJECT_TEST_NAME} ${GTEST_LIBRARIES})
else ()
  message(FATAL_ERROR "GTest required." )
endif (GTEST_FOUND)

add_test(tests ${PROJECT_TEST_NAME})
