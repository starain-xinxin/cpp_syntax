include_directories(.)

add_executable(shared_ptr shared_ptr.cpp)
add_executable(weak_ptr weak_ptr.cpp)
add_executable(weak_ptr2 weak_ptr2.cpp)
add_executable(unique_ptr unique_ptr.cpp)

# 新加入的一些代码
add_executable(share share.cpp)
add_executable(unique unique.cpp)           