cmake_minimum_required (VERSION 2.8)
project (neuron)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(/Users/luciegodot/Documents/neuron/include /Users/luciegodot/Documents/neuron)

add_executable (neuron neuron.h neuron.cpp network.h network.cpp main_neuron.cpp )



