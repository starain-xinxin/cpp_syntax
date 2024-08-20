//
// Created by mac on 2024/8/18.
// 这是一个错误代码，展示const修饰变量不可更改的性质
// 但应注意，const变量并非完全不可修改
//
#include<iostream>

int main(){
    int a = 100;
    int * const p1 = &a;
    // p1 = nullptr; // 编译无法通过
    *p1 = 200;

    const int* p2 = &a;
    p2 = nullptr;
    // *p2 = 200;  // 编译无法通过
    a = 400;

    const int i = 10;
    // i = 11;  // 编译无法通过
}