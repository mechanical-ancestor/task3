cmake_minimum_required(VERSION 3.5)

project(ma_3)
project(Manacher)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_LIBS})

add_executable(ma_3 ma_3.cpp)
add_executable(Manacher Manacher.cpp)

target_link_libraries(ma_3 ${OpenCV_LIBS})
target_link_libraries(Manacher ${OpenCV_LIBS})