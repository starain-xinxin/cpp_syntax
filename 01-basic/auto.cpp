//
// Created by mac on 2024/8/19.
//
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

#define Print(x) std::cout << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl

int main(){
    //  auto 只能推断出类型，引用不是类型，所以 auto 无法推断出引用，要使用引用只能自己加引用符号。
    int a = 100;
    auto a1 = a;
    Print(a1);
    auto& a2 = a;
    Print(a2);

    // auto  关键字在推断引用的类型时：会直接将引用替换为引用指向的对象。
    // 其实引用 一直是这样的，引用不是对象，任何使用引用的地方都可以直接替换成引用指向的对象。
    int b = 200;
    const int& b1 = b;
    auto b2 = b1;       // 等价于 auto b2 = b;
    Print(b1);
    Print(b2);

    // auto 关键字在推断类型时，如果没有引用符号，会忽略值类型的 const 修饰，而保留 修饰指向对象的 const，典型的就是指针。
    int c = 100;
    const int* const pc = &c;
    auto p2 = pc;		// 没有引用符号，忽略指针值 const，保留指针指向const
    Print(p2);

    // auto 关键字在推断类型时，如果有了引用符号，那么值类型的 const 和修饰指向对象 的 const 都会保留。
    int d = 128;
    const int* const d1 = &d;
    auto& d2 = d1;

}