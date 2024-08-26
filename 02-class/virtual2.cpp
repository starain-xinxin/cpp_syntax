//
// Created by mac on 2024/8/23.
// 这个代码说明析构函数最好使用虚函数，防止内存泄漏
//
#include <iostream>
#define LINE std::cout << "---------------------------------------" << std::endl

class Base {
public:
    Base() {
        std::cout << "Base 构造" << std::endl;
    }
    ~Base() {  // 非虚析构函数
        std::cout << "Base 析构" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        data = new int[100];  // 分配内存
        std::cout << "Derived 构造" << std::endl;
    }
    ~Derived() {
        delete[] data;  // 释放内存
        std::cout << "Derived 析构" << std::endl;
    }

private:
    int* data;
};

int main() {
    Base* obj = new Derived();  // 基类指针指向派生类对象
    delete obj;                 // 通过基类指针删除对象
    LINE;
    Derived* p = new Derived(); // 派生指针指向派生类对象
    delete p;                   // 派生指针指向派生类对象
}
