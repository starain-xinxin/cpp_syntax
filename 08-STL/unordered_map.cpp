#include <iostream>
#include <unordered_map>
#include <string>

struct DATA{
    int Id;
};

int main(){
    std::unordered_map<std::string, DATA> student_map;
    student_map["Alice"].Id = 1001;
    student_map["Bob"].Id = 1002;
    student_map["Charlie"].Id = 1003;

    // 1. 插入元素
    student_map.insert(std::make_pair("David", DATA{1004}));            // insert()函数  // TODO 这里的make_pair()函数是什么？
    student_map.emplace("Eve", 1005);                                                 // emplace()函数
    student_map["Frank"] = DATA{1006};                                            // operator[]赋值

    // 2. 访问元素
    std::cout << "Alice's Id is: " << student_map["Alice"].Id << std::endl;
    auto& Bob_data = student_map.at("Bob");
    std::cout << "Bob's Id is: " << Bob_data.Id << std::endl;
    std::cout << "haha's ID is: " << student_map["haha"].Id << "   -->  本来没有haha这个学生，但使用[]访问时，会自动插入一个空的元素，所以返回的Id是0" << std::endl;

    // 3. 查询元素
    auto data_iter = student_map.find("Charlie");
    std::cout << "Charlie's Id is: " << data_iter->second.Id << std::endl;

    // 4. 遍历元素
    std::cout << "使用for循环简化迭代输出" << std::endl;
    for(auto iter : student_map){
        std::cout << iter.first << "'s Id is: " <<iter.second.Id << std::endl;
    }
    std::cout << "使用原始方法" << std::endl;
    for(auto it = student_map.begin(); it != student_map.end(); it++){
        std::cout << it->first << "'s Id is: " << it->second.Id << std::endl;
    }

    // 5. 查询是否存在
    std::cout << "使用count()函数" << std::endl;
    if(student_map.count("Alice")){
        std::cout << "Alice is in the map" << std::endl;
    }
    else{
        std::cout << "Alice is not in the map" << std::endl;
    }
    if(student_map.count("wuwuwuw")){
        std::cout << "Alice is in the map" << std::endl;
    }
    else{
        std::cout << "wuwuwuw is not in the map" << std::endl;
    }
    


}