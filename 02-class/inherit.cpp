//
// Created by mac on 2024/8/23.
//

#include<iostream>
#include<string>
#include <utility>

class Base{
public:
    std::string name;
    Base(std::string  name_, int time_, std::string  icon_)
    : name(std::move(name_)), time(time_), icon(std::move(icon_)) {std::cout << "Base 构造" << std::endl;}
    ~Base(){std::cout << "Base 析构" << std::endl;}
    [[nodiscard]] std::string get_name() const{
        return name;
    }

protected:
    int time;
    [[nodiscard]] int get_time() const{
        return time;
    }

private:
    std::string icon;
    std::string get_icon(){
        return icon;
    }
};

class A : public Base{
public:
    int a;
    A(std::string  name_, int time_, std::string  icon_, int a_)
    : Base(std::move(name_), time_, std::move(icon_)), a(a_) {std::cout << "A 构造" << std::endl;}
    ~A(){std::cout << "A 析构" << std::endl;}

    int get_base_time(){
        //return time;  // 这是合法的
        return this->get_time();
    };

    // 无法访问
    // int get_base_icon(){
    //     return icon;
    //     return this->get_icon();
    // }
};
int main(){
    A aaa("a", 10, "aaa", 20);
    std::cout << aaa.a << "  " << aaa.name << std::endl;
    // aaa.icon;  aaa.time;    // 非法
    std::cout << aaa.get_base_time() << std::endl;
    std::cout << aaa.get_name() << std::endl;
    // std::cout << aaa.get_time() << std::endl;    // 非法
    // std::cout << aaa.get_icon() << std::endl;    // 非法

    A* p = new A("a", 10, "haha", 30);
    delete p;
}
