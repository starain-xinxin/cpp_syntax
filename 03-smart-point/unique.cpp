#include <memory>
#include <string>
#include <iostream>

class Basic{
public:
    Basic(std::string name_): name(name_) {}
    std::string GetName() const {
        return this->name;
    }
    void SetName(std::string& name_){
        this->name = name_;
    }

    int number = 10;

private:
    std::string name;
};

class ClassTest{
private:
    ClassTest(){}
    
};

int main(){
    /* ----------------------------------- 创建unique_ptr的三种方式 ------------------------------------------- */
    // 1. 通过 已有的裸指针 创建
    Basic* p_a = new Basic("Basic-A");
    std::unique_ptr<Basic> p_A(p_a);
    p_a = nullptr;
    // 2. 通过 new 创建
    std::unique_ptr<Basic> p_B(new Basic("Basic-B"));
    // 3. make_unique 最推荐，但是需要c++14
    std::unique_ptr<Basic> p_C = std::make_unique<Basic>("Basic-C");
    // 4. 通过智能指针移动构造
    std::unique_ptr<Basic> p_C_copy = std::move(p_C);

    /* ----------------------------------- 使用unique_ptr ------------------------------------------- */
    // 1. 调用类函数
    std::cout << "A's name is " << p_A->GetName() << std::endl;
    std::cout << "B's name is " << (*p_B).GetName() << std::endl;
    // 2. 调用类成员
    std::cout << "A's rank is " << p_A->number << std::endl;
    std::cout << "B's rank is " << (*p_B).number << std::endl;
    
    /* ----------------------------------- 查看移动构造的形式 ------------------------------------------- */
    std::cout << "C_copy's name is " << p_C_copy->GetName() << std::endl;
    std::cout << "C_copy's rank is " << p_C_copy->number << std::endl;
    // std::cout << "C's name is " << p_C->GetName() << std::endl;  // 非法代码
    // std::cout << "C's rank is " << p_C->number << std::endl;     // 非法代码

    /* ----------------------------------- 查看移动构造的形式 ------------------------------------------- */
    
    
        
}