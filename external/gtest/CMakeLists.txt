# adapted from https://github.com/snikulov/google-test-examples/blob/master/ext/gtest/CMakeLists.txt
cmake_minimum_required(VERSION 3.2.3 FATAL_ERROR)
project(gtest_builder C CXX)
include(ExternalProject)

ExternalProject_Add(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  CMAKE_ARGS -DCMAKE_CXX_FLAGS=${MSVC_COMPILER_DEFS}
             -Dgtest_force_shared_crt=ON
             -DBUILD_GTEST=ON
   PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
  INSTALL_COMMAND ""  # Disable install step
)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include PARENT_SCOPE)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR ${binary_dir}/googlemock/gtest PARENT_SCOPE)
