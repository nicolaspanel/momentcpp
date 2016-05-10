
cmake_minimum_required (VERSION 3.2.3 FATAL_ERROR)

# set and check compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall")

set(PROJECT_NAME          moment)
set(PROJECT_TEST_NAME     ${PROJECT_NAME}_test)
set(VERSION               "1.0.0")

project (${PROJECT_NAME} C CXX)
set(CMAKE_BUILD_TYPE Release)
find_package(Threads REQUIRED) # required by gtest

# Set project variables
set(SOURCES_DIR           "${PROJECT_SOURCE_DIR}/include")
set(EXTERNAL_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/external")

include_directories (${SOURCES_DIR})

add_library(${PROJECT_NAME}
  src/moment.cpp)
add_executable (main main.cpp)
target_compile_options(${PROJECT_NAME}  PUBLIC -std=c++14 -g -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -pedantic)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/lib)

#---- TEST ----
add_subdirectory(${EXTERNAL_PROJECTS_DIR}/gtest)

enable_testing()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_LIBS_DIR}/libgtest.a)
target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(tests ${PROJECT_TEST_NAME})
