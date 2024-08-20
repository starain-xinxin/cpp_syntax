//
// Created by mac on 2024/8/20.
//

#include<iostream>
#include<functional>

#define Print(x) std::cout << x << std::endl

// 函数调用
void test(int i){
    Print(i);
    Print("hello,world!");
}
using func_ptr = void(*)(int);
using func_ptr2 = std::function<void(int)>;

void CallFunc(func_ptr func, int i){
    Print("-------------- call-func -------------------");
    func(i);
    Print("-------------- call-func -------------------");
}

void CallFunc2(func_ptr2 func, int i){
    Print("-------------- call-func2 -------------------");
    func(i);
    Print("-------------- call-func2 -------------------");
}

int main(){
    // 函数调用
    CallFunc(test, 1);

    // lambda表达式
    int i = 100,j=200,k=300;
    int a = 168;
    auto result = [=,&a](int elem)->bool {
        Print(elem);
        Print(i); Print(j); Print(k);
        a = 234;
        Print("change a");
        return true;
    }(111);
    Print(result);
    Print(a);

    // lambda表达式作为参数
    CallFunc([](int elem){Print(elem);Print("haha");}, 10);
    // CallFunc([=](int elem){Print(elem);Print("haha");}, 10);  // 捕获不为空，报错
    // |
    // |
    // V
    CallFunc2([=](int elem){Print(elem);Print("haha");Print(a);}, 10);  // function解决了捕获问题
}
