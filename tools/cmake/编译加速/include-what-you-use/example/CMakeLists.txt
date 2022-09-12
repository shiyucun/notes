
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(example LANGUAGES CXX)

add_executable(example)
target_sources(example
 PRIVATE
  example.cc
)
