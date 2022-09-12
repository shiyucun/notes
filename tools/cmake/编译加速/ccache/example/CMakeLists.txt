cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(ccache-test LANGUAGES CXX)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif()

add_executable(ccache-test)
target_sources(ccache-test
 PRIVATE
  src/main.cc
  src/math.cc
)
target_include_directories(ccache-test
 PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

