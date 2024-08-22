//
// Created by mac on 2024/8/21.
//

#include<iostream>

class A{
    friend class aa;
    friend void print_old(A);
private:
    int old = 10;
};

class aa{
public:
    void print_A_old(A a){
        std::cout << a.old << std::endl;
    }
};

void print_old(A a){
    std::cout << a.old << std::endl;
}

int main(){
    A a1;
    aa a2;
    a2.print_A_old(a1);
    print_old(a1);
}