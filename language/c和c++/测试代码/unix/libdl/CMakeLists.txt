cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(unix_test_code LANGUAGES C)

add_library(dl_so SHARED)
target_sources(dl_so
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/adder.c
)
target_include_directories(dl_so
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(dl_so_test)
target_sources(dl_so_test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(dl_so_test
  PRIVATE
    dl_so
)

add_executable(dynamic_test)
target_sources(dynamic_test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dynamic.c
)
target_link_libraries(dynamic_test
  PRIVATE
    dl
)

