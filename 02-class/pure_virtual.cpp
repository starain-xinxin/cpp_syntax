//
// Created by mac on 2024/8/26.
//
#include<iostream>

class Base{
public:
    int basic_speed;

    Base(int basic_speed_): basic_speed(basic_speed_){}
    ~Base() = default;

    virtual int run_speed() = 0;
};

class Human : Base{
public:
    Human(int basic_speed_): Base(basic_speed_){}
    ~Human() = default;

    int run_speed(){
        return 2 * basic_speed;
    }
};

class Horse : Base{
public:
    Horse(int basic_speed_): Base(basic_speed_){}
    ~Horse() = default;

    int run_speed(){
        return 4 * basic_speed;
    }
};

int main(){
    // Base base;   // 无法产生对象

    Human human(1);
    Horse horse(5);

    std::cout << human.run_speed() << std::endl;
    std::cout << horse.run_speed() << std::endl;
}