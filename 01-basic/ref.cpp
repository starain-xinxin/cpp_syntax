//
// Created by mac on 2024/8/20.
//

int get(){
    return 100;
}

int main(){
    int i = 100;
    int&& rRefI = (i+1);	// 绑定右值
    int&& rRefA = get();
    // int&& rRefI = (i+1);	// 绑定左值
}