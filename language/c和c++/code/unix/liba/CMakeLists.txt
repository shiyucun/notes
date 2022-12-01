cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(liba LANGUAGES C)

add_library(adder STATIC)
target_sources(adder
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/adder.c
)
target_include_directories(adder
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(adder_test)
target_sources(adder_test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(adder_test
  PRIVATE
    adder
)
