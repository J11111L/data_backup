#!/bin/bash

echo "正在编译程序..."

qmake backup.pro
make -j$(nproc)

echo "编译完成,正在运行程序..."

./backup