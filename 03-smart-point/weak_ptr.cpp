//
// Created by mac on 2024/8/27.
// 此代码展示循环引用问题
//

#include<iostream>
#include<memory>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

class B;

class A{
public:
    std::shared_ptr<B> p_B;
};

class B{
public:
    std::shared_ptr<A> p_A;
};

int main(){
    // shared_ptr 循环引用的问题
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->p_B = b;
    b->p_A = a;

    PT(a.use_count(), "A实例的引用计数");
    PT(b.use_count(), "B实例的引用计数");

    auto p1 = a.get();
    auto p2 = b.get();

    a.reset();
    b.reset();

    PT(p2->p_A.use_count(), "查看A示例是否存在：");      // 可以发现还存在
    PT(p1->p_B.use_count(), "查看B示例是否存在：");
}