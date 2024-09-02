#include <iostream>
using namespace std;

class A {
protected:
    int* ptr;

public:
    A() {
        ptr = new int;
        cout << "Constructor of class A" << endl;
    }

    virtual ~A() {
        delete ptr;
        cout << "Destructor of class A" << endl;
    }
};

class B : public A {
private:
    int* anotherPtr;

public:
    B():A() {
        anotherPtr = new int;
        cout << "Constructor of class B" << endl;
    }

    ~B()  {
        delete anotherPtr;
        cout << "Destructor of class B" << endl;
    }
};

int main() {
    B bObject;
    return 0;
}
