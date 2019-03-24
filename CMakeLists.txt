# CMake最低版本号要求
cmake_minimum_required(VERSION 2.8)

# message
#message(STATUS "!!!!!!!!!!!!!!!!,CMAKE_GENERATOR := ${CMAKE_GENERATOR}")
#message(STATUS "++++++++++++++++,CMAKE_CURRENT_SOURCE_DIR := ${CMAKE_CURRENT_SOURCE_DIR}")

# 项目信息
project(demo)
#添加math子目录
add_subdirectory(math)
#添加openssl_util子目录
add_subdirectory(openssl_util)

# 设定头文件路径
set(test_includes math/)

# 设定代码依赖库
set(test_depends MathFunctions)

#设定测试代码路径
set(test_path "${CMAKE_CURRENT_SOURCE_DIR}/test")
#遍历所有cpp文件，每一个cpp文件是一个独立的测试程序
file(GLOB test_sources "${test_path}/*.cpp")

# 语法:对一个list中的每一个变量执行一组命令
# 递归为每个cpp文件指定一个可执行程序目标
foreach(source ${test_sources})
	# 语法:得到一个完整文件名中的特定部分
	get_filename_component(name "${source}" NAME_WE)
	set(the_target "${PROJECT_NAME}_${name}")
	# 指定生成目标 
	add_executable(${the_target} ${source})
	# 添加头文件路径
	target_include_directories(${the_target} PRIVATE ${test_includes})
	# 添加链接库
	target_link_libraries(${the_target} ${test_depends})
	message(STATUS "CMAKE_BIN_PATH=${CMAKE_BIN_PATH}")
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${CMAKE_BIN_PATH})
endforeach()