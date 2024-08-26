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

class Human : public Base{
public:
    Human(int basic_speed_): Base(basic_speed_){}
    ~Human() = default;

    int run_speed(){
        return 2 * basic_speed;
    }

    std::string str = "student";
    void write(){
        std::cout << "i am a " << str << std::endl;
    }
};

class Horse : public Base{
public:
    Horse(int basic_speed_): Base(basic_speed_){}
    ~Horse() = default;

    int run_speed(){
        return 4 * basic_speed;
    }

    float height = 20;
    void high(){
        std::cout << height << std::endl;
    }
};

int main(){
    Base* p1 = new Human(1);
    Base* p2 = new Human(3);
    Base* p3 = new Horse(5);

    std::cout << typeid(*p1).name() << std::endl;
    std::cout << typeid(*p2).name() << std::endl;
    std::cout << typeid(Human).name() << std::endl;
    std::cout << typeid(*p3).name() << std::endl;
    std::cout << typeid(Horse).name() << std::endl;

    std::cout << typeid(*p1).hash_code() << std::endl;
    std::cout << typeid(*p2).hash_code() << std::endl;
    std::cout << typeid(Human).hash_code() << std::endl;
    std::cout << typeid(*p3).hash_code() << std::endl;
    std::cout << typeid(Horse).hash_code() << std::endl;

    // 使用子类特性必须转换为子类指针 --> dynamic_cast
    // p1->str;
    // p1->write();
    if (std::string(typeid(*p2).name()) == std::string(typeid(Human).name())){
        Human* p_human2 = dynamic_cast<Human*>(p2);
        if(p_human2){
            std::cout << "cast human point success" << std::endl;
            p_human2->write();
        }
        else{
            std::cout << "cast human point error" << std::endl;
        }
    }

    if (typeid(*p3).hash_code() == typeid(Horse).hash_code()){
        Horse* p_horse1 = dynamic_cast<Horse*>(p3);
        if(p_horse1){
            std::cout << "cast human point success" << std::endl;
            p_horse1->high();
        }
        else{
            std::cout << "cast human point error" << std::endl;
        }
    }

}
