//
// Created by mac on 2024/8/21.
//

#include<iostream>
#include<string>

class AB{
public:
    int a;
    std::string b;
    mutable unsigned int OutputConstCount = 0;      // mutable关键字一般只用于统计调用次数等

    AB(int a_, std::string b_): a(a_), b(std::move(b_)){};
    AB(const AB&) = default;                        // default 与 delete 关键字使用
    AB& operator = (const AB& ab) = delete;

    AB* get_ptr(){
        return this;
    }

    void output() const{
        // a = 2 * a;  // 错误的
        OutputConstCount++;
        std::cout << "常成员函数 a:" << this->a << "  b:" << b << std::endl;
    }

    void output() {
        a = 2 * a;
        std::cout << "成员函数 a:" << this->a << "  b:" << b << std::endl;
    }
};

int main(){
    const AB ab1(10, "ab1");
    ab1.output();
    ab1.output();
    ab1.output();
    std::cout << ab1.OutputConstCount << std::endl;

    AB ab2(20,"ab2");
    ab2.output();

    // AB* p = ab1.get_ptr();   // 错误，常对象不可以调用非常成员函数
    AB* p = ab2.get_ptr();
    std::cout << p << std::endl;

}