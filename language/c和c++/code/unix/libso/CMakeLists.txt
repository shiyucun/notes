cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(libso LANGUAGES C)

add_library(adder_so SHARED)
target_sources(adder_so
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/adder.c
)
target_include_directories(adder_so
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(adder_so_test)
target_sources(adder_so_test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(adder_so_test
  PRIVATE
  adder_so
)
