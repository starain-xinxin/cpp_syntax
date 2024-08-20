//
// Created by mac on 2024/8/18.
//
#include<iostream>

class abc{
public:
    int a;
    float b;
    char c;

    abc():
    a(0), b(1.5), c('c'){}
};

int main(){
    // new 简单类型
    int* k = new int(10);
    std::cout << *k << std::endl;
    delete k;
    // new 类对象，将调用构造函数
    abc* p_abc = new abc;
    std::cout << p_abc->a << std::endl;
    std::cout << p_abc->b << std::endl;
    std::cout << p_abc->c << std::endl;
    delete p_abc;
    // new 普通数组
    int* arr = new int[100]();
    std::cout << arr[10] << std::endl;
    delete[] arr;
    // new 对象数组
    abc* abcs = new abc[10];
    std::cout << abcs[2].b << std::endl;
    delete[] abcs;
}