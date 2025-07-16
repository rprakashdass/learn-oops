#include <iostream>
using namespace std;

// Abstract base class with a pure virtual function
class BaseClass {
public:
    // Pure virtual function making this class abstract
    virtual void display() = 0;
};

// Derived class implementing the pure virtual function
class DerivedClass1 : public BaseClass {
public:
    // Implementing the pure virtual function
    void display() {
        cout << "Display called from DerivedClass1" << endl;
    }
};

// Another derived class implementing the pure virtual function differently
class DerivedClass2 : public BaseClass {
public:
    // Implementing the pure virtual function
    void display() {
        cout << "Display called from DerivedClass2" << endl;
    }
};

int main() {
    // BaseClass baseClass; // This will cause a compile-time error as BaseClass is abstract

    // Pointers to the base class can be used to point to derived class objects
    BaseClass* ptr1 = new DerivedClass1();
    BaseClass* ptr2 = new DerivedClass2();

    // Calling implemented functions through base class pointers
    ptr1->display();
    ptr2->display();

    // Cleanup
    delete ptr1;
    delete ptr2;

    return 0;
}

/*
OUTPUT:
Display called from DerivedClass1
Display called from DerivedClass2
*/
