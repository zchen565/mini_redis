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

    bool Register() {
        return true;
    }

    bool Enroll() {
        return true;
    }
};


int main() {
    Student* p = new Student();
    if (!p->Register()) {
        delete p;
        return -1;
    }

    if (!p->Enroll()) {
        delete p;
        return -2;
    }

    delete p;
    return 0;
}


