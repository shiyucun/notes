
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(gch-example)

option(ENABLE_PRE_COMPILE "enable precompile" OFF)

add_executable(main src/main.cc)
target_include_directories(main
 PRIVATE
  include
)
if (ENABLE_PRE_COMPILE)
  target_precompile_headers(main
  PRIVATE
    include/hello.hpp
  )
endif()
