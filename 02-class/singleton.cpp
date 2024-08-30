//
// Created by mac on 2024/8/30.
//

#include<iostream>
#include<string>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

/* c++11 标准做法
 * c++11 规定局部静态变量的初始化是多线程安全的。
 * */
class Singleton1{
public:
    std::string name;

    static Singleton1& getInstance(){
        static Singleton1 instance;
        return instance;
    }

    static void rename(const std::string& new_name){
        Singleton1& instance = Singleton1::getInstance();
        instance.name = new_name;
    }

private:
    Singleton1(){name = "hello from instance1";};
    ~Singleton1() = default;
    Singleton1(const Singleton1&) = delete;
    Singleton1& operator= (const Singleton1&) = delete;
};
/* 局部静态变量可以通过指针或引用访问 */
int& add(){
    static int count = 0;
    count++;
    return count;
}

/* 2. 单例模式 饿汉式
 * 依靠“私有化构造函数”和“静态类成员变量”来构建单例
 * */
class Singleton2{
public:
    std::string name = "hh";
    static Singleton2& getInstance(){
        return instance2;
    }

private:
    static Singleton2 instance2;
    Singleton2(){name = "hello from instance2";};
    ~Singleton2() = default;
    Singleton2(const Singleton2&) = delete;
    Singleton2& operator= (const Singleton2&) = delete;
};
Singleton2 Singleton2::instance2;

int main(){
    /* 1. 单例模式 c++11标准写法，懒汉式 */
    Singleton1& instance1 = Singleton1::getInstance();
    PT(instance1.name,"");
    instance1.rename("rename complete");
    PT(instance1.name,"");
    /* 局部静态变量可以通过指针或引用访问 */
    int& c = add();
    c = c + 100;
    std::cout << c << std::endl;

    /* 2. 单例模式 饿汉式 */
    Singleton2& instance2 = Singleton2::getInstance();
    PT(instance2.name,"");

}