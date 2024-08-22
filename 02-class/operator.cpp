//
// Created by mac on 2024/8/22.
//
//
#include<iostream>

class cVector{
public:
    float* p_vec;
    std::size_t count;

    /* 构造函数 */
    explicit cVector(int count_): p_vec(new float[count_]), count(count_) {}
    cVector(const float* p_vec_, unsigned int count_): count(count_){
        p_vec = new float[count_];
        for(int i=0; i<count_; i++){
            p_vec[i] = p_vec_[i];
        }
    }

    /* 移动构造函数 */
    cVector(cVector&& v) noexcept : p_vec(v.p_vec), count(v.count) {
        std::cout << "移动构造函数" << std::endl;
        v.p_vec = nullptr;
        v.count = 0;
    }

    /* 移动赋值运算符的重载 */
    cVector& operator = (cVector&& v)   noexcept {
        std::cout << "移动赋值运算符的重载" << std::endl;
        if (this == &v) return *this; // 防止自赋值
        count = v.count;
        p_vec = v.p_vec;
        v.count = 0;
        v.p_vec = nullptr;
        return *this;
    }

    ~cVector(){delete[] p_vec;}

    // 一元运算符重载
    cVector& operator ++ () {
        for(int i=0; i<count; i++){
            p_vec[i]++;
        }
        return *this;
    }

    cVector& operator ++ (int) {
        for(int i=0; i<count; i++){
            p_vec[i]++;
        }
        return *this;
    }

    // 二元运算符重载
    cVector operator + (const cVector& v2) const {
        if (count != v2.count){
            throw std::runtime_error("vector's shape error");
        }
        cVector tmp(count);
        for(int i=0; i<count; i++){
            tmp.p_vec[i] = p_vec[i] + v2.p_vec[i];
        }
        return std::move(tmp);
    }

    // 一般的输出
    void Print(){
        std::cout << "{ ";
        for(int i=0; i<count; i++){
            std::cout << p_vec[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

    // 重载输出函数
    friend std::ostream& operator << (std::ostream& , const cVector&);
    // 重载输入函数
    friend std::istream& operator >> (std::istream& , cVector&);    // 未实现

};

std::ostream& operator << (std::ostream& os, const cVector& v){
    os << "{ ";
    for(int i=0; i<v.count; i++){
        os << v.p_vec[i] << " ";
    }
    os << "}";
    return os;
}


int main(){
    float v1_[5] = {1,2,3,4,5};
    float v2_[5] = {1,2,3,4,5};
    cVector v1(v1_, 5);
    cVector v2(v2_, 5);
    v1.Print();
    v2.Print();

    v1 = v1 + v2;
    std::cout << v1 << std::endl;

    ++v2;
    v2++;
    std::cout << v2 << std::endl;

    cVector v3 = v1 + v2;
    std::cout << v3 << std::endl;
}