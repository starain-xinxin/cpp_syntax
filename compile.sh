#!/bin/bash

# 创建构建目录
rm -rf build
mkdir -p build

# 进入构建目录
cd build

# 运行cmake配置
cmake -DCMAKE_BUILD_TYPE=Debug ..

# 编译项目
cmake --build .