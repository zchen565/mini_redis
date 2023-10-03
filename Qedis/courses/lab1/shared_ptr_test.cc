#include <string.h>
#include <stdio.h>
#include <memory>
#include <thread>
#include <iostream>

using namespace std;

typedef int Resourse;

shared_ptr<Resourse> CreateResourse() {
    return make_shared<Resourse>(1);
}

void User1(shared_ptr<Resourse> p) {
    if (p) {
        //1 使用p
        cout << "use p in user1 thread." << endl;
    }
    return;
}

void User2(shared_ptr<Resourse> p) {

    this_thread::sleep_for(chrono::milliseconds(10));

    if (p) {
        //2 使用p
        cout << "use p in user2 thread." << endl;
    }
    return;
}

int main() {
    shared_ptr<Resourse> res = CreateResourse();

    // 启动线程t1和t2，运行user函数，使用res
    thread t1(User1, res);
    thread t2(User2, res);

    // 等待线程结束，谁也不需要考虑res资源的释放
    t1.join();
    t2.join();
    return 0;
}


