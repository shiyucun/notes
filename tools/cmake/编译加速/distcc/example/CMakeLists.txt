cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(distcc-test LANGUAGES CXX)

find_program(DISTCC_FOUND distcc)
if (DISTCC_FOUND)
  message(STATUS "distcc found.")
  set(CMAKE_CXX_COMPILER_LAUNCHER distcc)
endif()

add_executable(distcc-test)
target_sources(distcc-test
  PRIVATE
    src/add.cc
    src/multi.cc
    src/sub.cc
    src/main.cc
)
target_include_directories(distcc-test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
