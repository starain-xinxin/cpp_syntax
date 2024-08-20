//
// Created by mac on 2024/8/20.
//
#include<iostream>
#include<string>
#include <utility>

#define Print(x) std::cout << x << std::endl

class ABC{
public:
    int a;
    float b;
    std::string c;
    int *p;

    // 普通构造函数
    ABC(int a_, float b_, std::string c_, int pp)
    : a(a_), b(b_), c(std::move(c_)), p(new int(pp)){Print("调用普通构造函数");}

    // 复制构造函数
    ABC(const ABC& abc)
    : a(abc.a), b(abc.b), c(abc.c), p(new int(* abc.p)){Print("调用复制构造函数");}    // 默认的写法： ABC(const ABC&) = default;  // 让编译器自动生成复制构造函数

    // 赋值运算符重载
    ABC& operator = (const ABC& abc){
        Print("调用赋值运算符重载函数");
        a = abc.a; b = abc.b; c = abc.c; *p = *abc.p;
        return *this;
    }

    // 析构函数
    ~ABC(){
        delete p;
        Print("调用析构函数");
    }

    // 打印
    static void printABC(ABC abc) {
        std::cout << abc.a << ", " << abc.b << ", " << abc.c  << *abc.p << std::endl;
    }
};


int main(){
    // 普通构造函数
    Print("-------------------------------");
    std::string str1 = "layer";
    ABC abc1(1, 2, str1, 10);

    // 复制构造函数调用
    Print("-------------------------------");
    ABC abc2 = abc1;            // 这里调用了复制构造函数
    ABC::printABC(abc2);    // 值传递调用复制构造函数

    // 赋值运算符号
    Print("-------------------------------");
    abc1 = abc2;        // 这里会调用赋值运算符

    // 析构函数
    Print("-------------------------------");
    ABC* p_abc = new ABC(abc2);
    delete p_abc;


    Print("-------------------------------");
    Print("退出main函数，操作系统退栈，调用析构函数");

}
