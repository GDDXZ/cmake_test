# 设置openssl依赖库
set(libraryname OpenSSLUTIl)
set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
#set(OPENSSL_LIBRARIES /usr/local/opt/openssl/lib)
find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
	message(STATUS "openssl-lib position: +++ ${OPENSSL_INCLUDE_DIR}")
	set(depend_linklibs ${depend_linklibs} ${OPENSSL_LIBRARIES})
    set(depend_includes ${depend_includes} ${OPENSSL_INCLUDE_DIR})
endif()

#查找当前目录下的所有源文件
#并将名称保存到DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)
#生成链接库
add_library(${libraryname} ${DIR_LIB_SRCS})
target_link_libraries(${libraryname} ${depend_linklibs})
target_include_directories(${libraryname} PRIVATE ${depend_includes})