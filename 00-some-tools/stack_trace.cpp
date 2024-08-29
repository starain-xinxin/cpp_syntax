//
// Created by mac on 2024/8/29.
//

#include <boost/stacktrace.hpp>
#include <iostream>

void PrintStackTrace() {
    std::cout << boost::stacktrace::stacktrace();
}

int main() {
    PrintStackTrace();
    return 0;
}
