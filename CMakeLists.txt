# 指定 CMake 的最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(code)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)

# 整合源文件
aux_source_directory(${PROJECT_BINARY_DIR}/../src SRC_LIST)

# 添加可执行文件
add_executable(${PROJECT_NAME}/src SRC_LIST)

# 设置目标文件的输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)