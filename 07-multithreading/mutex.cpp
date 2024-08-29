#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <cassert>

class Table {
public:
    std::map<std::string, int> home1;
    std::mutex mtx1;
    std::map<std::string, int> home2;
    std::mutex mtx2;
    std::map<std::string, int> home3;
    std::mutex mtx3;

    // 获取单例实例的方法
    static Table& getInstance() {
        static Table instance; // 局部静态变量，线程安全
        return instance;
    }

    // 删除拷贝构造函数和拷贝赋值运算符
    Table(const Table&) = delete;
    Table(Table&&) = delete;
    Table& operator=(const Table&) = delete;
    Table& operator=(Table&&) = delete;

    void init() {
        home1.insert({"a1", 10});
        home1.insert({"a2", 11});

        home2.insert({"b1", 12});
        home2.insert({"b2", 13});

        home3.insert({"c1", 14});
        home3.insert({"c2", 15});
    }

    static void exchange(std::map<std::string, int>& map1, std::map<std::string, int>& map2) {
        std::cout << std::this_thread::get_id() << std::endl;

        Table& table = getInstance();

        std::mutex* mtx1 = nullptr;
        std::mutex* mtx2 = nullptr;

        if (&map1 == &table.home1) mtx1 = &table.mtx1;
        if (&map1 == &table.home2) mtx1 = &table.mtx2;
        if (&map1 == &table.home3) mtx1 = &table.mtx3;

        if (&map2 == &table.home1) mtx2 = &table.mtx1;
        if (&map2 == &table.home2) mtx2 = &table.mtx2;
        if (&map2 == &table.home3) mtx2 = &table.mtx3;

        assert((mtx1 && mtx2) && "传入map有误。");

        if (mtx1 > mtx2) std::swap(mtx1, mtx2);

        std::scoped_lock lock(*mtx1, *mtx2);
        map1.swap(map2);
    }

private:
    Table() { init(); } // 构造函数是私有的，防止外部创建实例
};

int main() {
    Table& table = Table::getInstance();

    std::thread t1(Table::exchange, std::ref(table.home1), std::ref(table.home2));
    std::thread t2(Table::exchange, std::ref(table.home2), std::ref(table.home3));
    std::thread t3(Table::exchange, std::ref(table.home3), std::ref(table.home1));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
