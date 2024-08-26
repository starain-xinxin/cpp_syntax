//
// Created by mac on 2024/8/26.
//

#include<iostream>

class Test{
public:
    int kk;
    static unsigned int get_i(){
        i++;
        return i;
    }
private:
    static unsigned int i;
};
// 类静态成员变量需要在类外初始化
unsigned int Test::i = 20;

int main(){
    Test t;

    // std::cout << Test::i << std::endl;
    // std::cout << t.i << std::endl;           // i为私有，访问权限不够，需要静态函数

    std::cout << Test::get_i() << std::endl;
    std::cout << t.get_i() << std::endl;
}