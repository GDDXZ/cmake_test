#!/bin/bash

CWD=`pwd`

echo "命令行参数: 编译类型[r/d]"

# 默认是Release
build_type=Release
build_path=./build
exe_outpath=bin

if [ "$*" ]
then
	if [ "$1" == "d" ]
	then
		build_type=Debug
		echo "make Debug"
	fi
fi

rm -rf ${build_path}
rm -rf ${exe_outpath}
mkdir ${build_path}
cd ${build_path}

cmake -DCMAKE_BUILD_TYPE=${build_type} ../ -DCMAKE_BIN_PATH=${exe_outpath}

echo "cmake ${build_type} finished, press enter to make"
read
make

echo "press enter to run test"
read
cd ${CWD}
# echo "${CWD}/${exe_outpath}"
for i in ${exe_outpath}/*; do $i; done
echo "please check result"

read -p "press enter to make install or ctrl+c to stop"
cd ${build_path} && make install