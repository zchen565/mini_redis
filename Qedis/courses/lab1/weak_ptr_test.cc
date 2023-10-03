#include <string.h>
#include <stdio.h>
#include <memory>
#include <thread>
#include <iostream>

using namespace std;

typedef int Resourse;

shared_ptr<Resourse> g_resourse;

void thread_a() {
    // 2. 创建全局资源
    g_resourse = make_shared<Resourse>(1);

    // 3. 睡眠3秒钟
    this_thread::sleep_for(chrono::seconds(3));

    // 6. 释放资源
    g_resourse = nullptr;
    cout << "free resourse, thread A exit." << endl;
}

void thread_b() {
    //  1. 休眠，让线程A先创建资源
    this_thread::sleep_for(chrono::milliseconds(100));

    // 4. 创建weak_ptr访问资源,它可以有效检测出悬挂指针：
    weak_ptr<Resourse> pw(g_resourse);

    // 5. 隔一秒钟访问资源，若资源被释放了，则退出线程；
    int i = 0;
    while (1) {
        i++;

        // 调用weak_ptr的lock()尝试提升到shared_ptr
        auto res(pw.lock());

        if (res) {
            // 在6之前: 提升成功，指针res有效，可以使用资源，然后睡眠1秒钟
            cout << i << ":Success read resourse from thread B." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        } else {
            cout << "Fail read resourse from thread B, exit." << endl;
            return; // 7. 说明资源被释放了，出现了"悬挂指针"情况，线程退出
        }
    }
}

int main() {
    //启动线程A
    std::thread t_a(thread_a);
    //启动线程B
    std::thread t_b(thread_b);
    // 请注意看线程代码注释中的序号，大致代表了代码的执行顺序

    //等待线程结束
    t_a.join();
    t_b.join();
    return 0;
}

