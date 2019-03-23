#查找当前目录下的所有源文件
#并将名称保存到DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)
#	add_definitions(-DDEBUG)
#endif()
#生成链接库
add_library(MathFunctions ${DIR_LIB_SRCS})
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_compile_options(MathFunctions PRIVATE -DDEBUG=1)
endif()