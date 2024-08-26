//
// Created by mac on 2024/8/26.
//

#include<iostream>

#define PT(x) std::cout << x << std::endl

class Base{
public:
    int basic_value = 100;
    Base(int basic_value_): basic_value(basic_value_){PT("Base 构造函数");}
    virtual ~Base(){PT("Base 析构函数");}
};

class Base1: virtual public Base{
public:
    int share_i = 10;
    int base1;
    Base1(int basic_value_, int base1_):Base(basic_value_), base1(base1_){PT("Base1 构造函数");}
    virtual ~Base1(){PT("Base1 析构函数");}
};

class Base2: virtual public Base{
public:
    int share_i = 20;
    int base2;
    Base2(int basic_value_, int base2_):Base(basic_value_), base2(base2_){PT("Base2 构造函数");}
    virtual ~Base2(){PT("Base2 析构函数");}
};

class Test: public Base1, public Base2{
public:
    int value;
    Test(int basic_value_, int base1_, int base2_, int value_)
    : Base(basic_value_), Base1(basic_value_, base1_), Base2(basic_value_, base2_), value(value_)
    {PT("Test 构造函数");}
    virtual ~Test(){PT("Test 析构函数");}
};

int main(){
    Test t(1,2,3,4);
    PT(t.basic_value);
    PT(t.base1);
    PT(t.base2);
    PT(t.value);
    PT(t.Base1::share_i);
    PT(t.Base2::share_i);
}