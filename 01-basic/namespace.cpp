//
// Created by mac on 2024/8/18.
//
#include <iostream>

namespace A {
    void func() {
        std::cout << "Function from namespace A" << std::endl;
    }
}

namespace B {
    void func() {
        std::cout << "Function from namespace B" << std::endl;
    }
}

int main() {
    using namespace A;
    func();  // 调用A::func()

    B::func();  // 调用B::func()，需要显式指定命名空间
    return 0;
}

