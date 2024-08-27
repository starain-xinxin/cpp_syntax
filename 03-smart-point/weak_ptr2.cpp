//
// Created by mac on 2024/8/27.
//

#include<iostream>
#include<memory>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

int main(){
    std::shared_ptr<int> p = std::make_shared<int>(100);
    std::weak_ptr<int> p_weak(p);
    PT(p.use_count(), "引用计数");

    LINE;
    auto p_tmp = p_weak.lock();
    PT(*p_tmp, "堆内存内容");
    PT(p.use_count(), "引用计数");
    PT(p_weak.use_count(), "用weak指针查对象引用数");

    LINE;
    p_tmp.reset();
    p.reset();
    auto p_tmp2 = p_weak.lock();
    PT(p_tmp2, "堆内存释放后的lock行为");
    PT(p_weak.use_count(), "用weak指针查对象引用数");
}