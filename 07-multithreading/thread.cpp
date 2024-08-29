//
// Created by mac on 2024/8/29.
//

#include<iostream>
#include<thread>
#include<chrono>

#define PT(x, y) std::cout << y << ": " << x << std::endl
#define LINE std::cout << "---------------------------------------------" << std::endl

static int count = 0;
static std::atomic<int> count2 = 0;

void ADD1(){
    for(int i=0; i<10000; i++){
        count++;
    }
}

void ADD2(){
    for(int i=0; i<20000; i++){
        count = count + 2;
    }
}

void ADD3(){
    for(int i=0; i<10000; i++){
        count2++;
    }
}

void ADD4(){
    for(int i=0; i<20000; i++){
        count2.fetch_add(2);
    }
}

void Hello(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "hello from thread:" << std::this_thread::get_id();
}

int main(){
    std::thread t1(ADD1);
    std::thread t2(ADD2);
    std::thread t3(ADD3);
    std::thread t4(ADD4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::thread t5(Hello);
    t5.detach();

    PT(count, "count: ");
    PT(count2, "count2: ");

}
