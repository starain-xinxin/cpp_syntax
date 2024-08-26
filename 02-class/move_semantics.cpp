//
// Created by mac on 2024/8/26.
//

#include<iostream>

#define LINE(x) std::cout << "-------------------------------------" << x << "-------------------------------------" << std::endl
#define PT(x) std::cout << x << std::endl

class Data10{
public:
    int* p_data;
    int k = 10;

    /* 构造函数 */
    Data10(){
        PT("Data10 构造函数");
        p_data = new int[10];
        for(int i=0;i<10;i++){
            p_data[i] = 2 * i;
        }
    }

    /* 复制构造函数 */
    Data10(const Data10& other){
        PT("Data10 复制构造函数");
        p_data = new int[10];
        for(int i=0;i<10;i++){
            p_data[i] = other.p_data[i];
        }
    }

    /* 移动构造函数 */
    Data10(Data10&& other){
        PT("Data10 移动构造函数");
        p_data = other.p_data;
        other.p_data = nullptr;
    }

    /* 赋值运算符 */
    Data10& operator = (const Data10& other){
        PT("Data10 赋值运算符");
        if (this == &other){
            return *this;
        }
        if (other.p_data) {
            for (int i = 0; i < 10; i++) {
                p_data[i] = other.p_data[i];
            }
        }
        return *this;
    }

    /* 移动赋值运算符 */
    Data10& operator = (Data10&& other){
        PT("Data10 移动赋值运算符");
        if (this == &other){
            return *this;
        }
        p_data = other.p_data;
        other.p_data = nullptr;
        return *this;
    }

    /* 析构函数 */
    ~Data10(){
        PT("Data10 析构函数");
        delete[] p_data;
    }
};

int test(Data10 data){
    return 0;
}

Data10 func(){
    Data10 data;
    return data;
}

int main(){
    LINE("调用构造函数");
    Data10 data1;               // 初始化一个对象

    LINE("调用复制构造函数");
    Data10 data2 = data1;        // 对象被用来初始化另一个对象
    test(data1);            // 函数值传递

    LINE("调用移动构造函数");
    Data10 data3 = std::move(data2);    // 使用右值构造
    PT(data2.k);                        // data2并没有被释放

    LINE("调用赋值运算符");
    data1 = data3;

    LINE("调用移动赋值运算符");
    data2 = std::move(data3);

    LINE("操作系统释放资源");
}