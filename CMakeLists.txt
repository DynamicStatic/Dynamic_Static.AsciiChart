
#==========================================
#  Copyright (c) 2020 dynamic_static
#    Patrick Purcell
#      Licensed under the MIT license
#    http://opensource.org/licenses/MIT
#==========================================

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(dynamic_static.ascii-chart VERSION 1.0.0)
add_executable(
    dynamic_static.ascii-chart.examples
    "${CMAKE_CURRENT_LIST_DIR}/ascii-chart.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/ascii-chart.examples.cpp"
)
target_compile_features(dynamic_static.ascii-chart.examples PUBLIC cxx_std_17)
target_include_directories(dynamic_static.ascii-chart.examples PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
