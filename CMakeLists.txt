cmake_minimum_required(VERSION 2.5)
project(mymuduo)


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置调试信息 以及 启动C++11语言标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC -pthread")

# 定义参与编译的源代码文件 
aux_source_directory(. SRC_LIST)
add_library(mymuduo SHARED ${SRC_LIST})
add_executable(server ${SRC_LIST})