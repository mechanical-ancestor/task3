cmake_minimum_required(VERSION 3.10)
project(ma_test3)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建两个独立的可执行文件
add_executable(sentence_analyzer main1.cpp)
add_executable(palindrome_finder main2.cpp)

# 可选：设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 可选：添加编译选项
target_compile_options(sentence_analyzer PRIVATE -Wall -Wextra)
target_compile_options(palindrome_finder PRIVATE -Wall -Wextra)

# 可选：添加描述信息
message(STATUS "构建项目: ${PROJECT_NAME}")
message(STATUS "可执行文件1: sentence_analyzer (来自 main1.cpp)")
message(STATUS "可执行文件2: palindrome_finder (来自 main2.cpp)")