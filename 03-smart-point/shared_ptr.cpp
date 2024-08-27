//
// Created by mac on 2024/8/27.
//

#include<iostream>
#include<memory>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

int main(){
    std::shared_ptr<int> p1(new int(100));             // 构造函数
    std::shared_ptr<int> p21 = std::make_shared<int>(200);    // 移动构造函数
    std::shared_ptr<int> p22(p21);                   // 拷贝构造函数

    PT(*p1, "堆内存");
    PT(p1, "堆内存地址");
    PT(*p21, "堆内存");
    PT(p21, "堆内存地址");
    PT(*p22, "堆内存");
    PT(p22, "堆内存地址");

    LINE;

    PT(p1.use_count(), "堆内存计数");
    PT(p21.use_count(), "堆内存计数");
    PT(p22.use_count(), "堆内存计数");

    LINE;

    PT(p1.unique(), "是否独占");
    PT(p21.unique(), "是否独占");
    PT(p22.unique(), "是否独占");

    LINE;
    // 更改p21与p22指针
    PT(p22.use_count(), "堆内存计数");
    p21.reset();
    PT(p22.use_count(), "堆内存计数");
    p22.reset(new int(300));
    PT(p21, "堆内存地址");
    PT(*p22, "堆内存");
    PT(p22, "堆内存地址");

    LINE;
    p22.swap(p1);
    PT(*p1, "堆内存");
    PT(p1, "堆内存地址");
    PT(*p22, "堆内存");
    PT(p22, "堆内存地址");

    LINE;
    std::shared_ptr<int[]> p_array(new int[5]());   // c++17之后可以使用
    std::shared_ptr<int[]> p1_array = std::make_shared<int[]>(10, 3);       // c++20后使用
    for(int i=0; i<5; i++){
        p_array[i] = 2 * i + 2;                // c++17提供了operate[]
    }
    PT(p_array, "数组的堆内存地址");

    LINE;
    // C++17之前的数组写法
    std::shared_ptr<int> p2_array(new int[5](), std::default_delete<int[]>());
    for(int i=0; i<5; i++){
        p2_array.get()[i] = 2 * i + 1;
    }
    PT(p2_array, "数组的堆内存地址");
}