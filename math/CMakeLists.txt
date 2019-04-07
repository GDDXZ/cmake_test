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
message( STATUS "~~~~~~~~~~~utils_public_dir=${utils_public_dir}" )
set(install_include_dir ${utils_public_dir}/include/)
set(install_lib_dir ${utils_public_dir}/lib/)
message (STATUS "~~~~~~~~~~~install_include_dir=${install_include_dir}")
message (STATUS "~~~~~~~~~~~install_lib_dir=${install_lib_dir}")
#install(FILES  DESTINATION ${install_include_dir})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
		DESTINATION ${install_include_dir}
		FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
		DESTINATION ${install_include_dir}
		FILES_MATCHING PATTERN "*.hpp")
install(TARGETS ${library_name} ARCHIVE DESTINATION ${install_lib_dir})