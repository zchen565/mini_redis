#include <string.h>
#include <stdio.h>
#include <memory>
#include <iostream>

using namespace std;

class Student {
public:
    Student() {
        cout << "Construct student" << endl;
    }

    ~Student() {
        cout << "Destruct student" << endl;
    }

    bool Register(Student* p) {
        return true;
    }

    bool Enroll(Student* p) {
        return true;
    }
};


// 编译 g++ -std=c++11 -o unique_ptr_test unique_ptr_test.cc
int main() {
    unique_ptr<Student> p(new Student());
    if (!p->Register()) {
        // 不需要任何操作，p指向的资源会自动释放
        return -1;
    }

    if (!p->Enroll()) {
        // 不需要任何操作，p指向的资源会自动释放
        return -2;
    }

    // 不需要任何操作，p指向的资源会自动释放
    return 0;
}


