set(library_name MathFunctions)
#查找当前目录下的所有源文件
#并将名称保存到DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)
#if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#	add_definitions(-DDEBUG)
#endif()
#生成链接库
add_library(${library_name} ${DIR_LIB_SRCS})
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_compile_options(${library_name} PRIVATE -DDEBUG=1)
endif()