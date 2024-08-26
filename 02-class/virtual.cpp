//
// Created by mac on 2024/8/23.
//

#include <iostream>
#define LINE std::cout << "---------------------------------------" << std::endl

class Base {
public:
    // 构造函数
    Base() {
        std::cout << "Base 构造" << std::endl;
    }
    // 析构函数
    virtual ~Base() {
        std::cout << "Base 析构" << std::endl;
    }
    // 普通类函数(使用虚函数版)
    virtual void hello(){
        std::cout << "Base hello" << std::endl;
    }
};

class Derived : public Base {
public:
    // 构造函数
    Derived() {
        std::cout << "Derived 构造" << std::endl;
    }
    // 析构函数
    ~Derived() override {
        std::cout << "Derived 析构" << std::endl;
    }
    // 普通类函数
    void hello() override {
        std::cout << "Derived hello" << std::endl;
    }
};

int main() {
    Derived obj;
    LINE;
    obj.hello();
    LINE;
}
