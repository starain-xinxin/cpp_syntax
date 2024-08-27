//
// Created by mac on 2024/8/27.
//

#include<iostream>
#include<memory>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

void func1(std::unique_ptr<int> p){}
void func2(std::unique_ptr<int>& p){}

int main(){
    std::unique_ptr<int> p1 = std::make_unique<int>(100);   // 移动构造
    std::unique_ptr<int> p2(new int(200));                  // 移动构造函数
    std::unique_ptr<int> p3 = std::move(p2);                  // 移动赋值

    LINE;
    PT(p1, "p1堆内存地址");
    PT(*p1, "p1堆内存");
    PT(p2, "p2指针地址");
    PT(p3, "p3堆内存地址");
    PT(*p3, "p3堆内存");

    LINE;
    func1(std::move(p1));
    PT(p1, "p1指针地址");
    func2(p3);
    PT(p3, "p3指针地址");



}