//
// Created by mac on 2024/8/20.
//
#include<iostream>
#define Print(x) std::cout << x << std::endl

int global_num = 0;

class A{
public:
    static int class_num;
    A(){}

    int test_A(){
        class_num++;
    }
};
int A::class_num = 0;

int test(){
    static int i = 0;
    return i++;
}

int main(){
    global_num++;
    Print(global_num);


    A a = A();
    a.test_A();
    Print(a.class_num);

    test();test();test();
    Print(test());
}