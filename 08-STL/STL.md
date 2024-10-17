# STL各种容器的简介与API

## unordered_map
- 一个基于哈希表的存储结构，用于键值对数据的存储，数据是无序的。
- 查找、插入和删除操作的平均时间复杂度是 O(1)，非常高效
### API
1. 声明和初始化
    ```cpp
    #include <unordered_map>
    #include <string>

    std::unordered_map<std::string, int> myMap;
    myMap["apple"] = 3;
    myMap["banana"] = 5;
    ```
插入元素

使用 [] 运算符：
cpp
复制代码
myMap["orange"] = 4;  // 插入或更新键 "orange" 的值为 4
使用 insert 方法：
cpp
复制代码
myMap.insert({"grape", 2});  // 插入键值对 ("grape", 2)
使用 emplace 方法（效率更高，避免了不必要的拷贝）：
cpp
复制代码
myMap.emplace("pear", 6);
访问元素

使用 [] 运算符：
cpp
复制代码
int count = myMap["apple"];  // 如果键存在则返回对应值，如果不存在则插入默认值
使用 at 方法：
cpp
复制代码
try {
    int value = myMap.at("banana");  // 如果键不存在会抛出 std::out_of_range 异常
} catch (const std::out_of_range& e) {
    std::cout << "Key not found!" << std::endl;
}
查找元素

使用 find 方法：
cpp
复制代码
auto it = myMap.find("apple");
if (it != myMap.end()) {
    std::cout << "Found apple with value: " << it->second << std::endl;
} else {
    std::cout << "Apple not found." << std::endl;
}
find 返回一个迭代器，如果键不存在，返回 myMap.end()。
删除元素

使用 erase 方法：
cpp
复制代码
myMap.erase("banana");  // 删除键为 "banana" 的元素
也可以通过迭代器删除：
cpp
复制代码
auto it = myMap.find("grape");
if (it != myMap.end()) {
    myMap.erase(it);
}
检查元素是否存在

使用 count 方法：
cpp
复制代码
if (myMap.count("orange") > 0) {
    std::cout << "Orange is in the map." << std::endl;
} else {
    std::cout << "Orange is not in the map." << std::endl;
}
count 在 unordered_map 中只能返回 0 或 1，因为每个键在 unordered_map 中是唯一的。
遍历元素

cpp
复制代码
for (const auto& pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
大小和其他信息

获取大小：
cpp
复制代码
std::cout << "Size: " << myMap.size() << std::endl;
检查是否为空：
cpp
复制代码
if (myMap.empty()) {
    std::cout << "Map is empty." << std::endl;
}
