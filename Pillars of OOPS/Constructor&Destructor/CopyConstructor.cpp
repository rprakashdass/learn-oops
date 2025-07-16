#include <iostream>
using namespace std;

class Test {
public:
    int a, b;
    
    // Parameterized constructor
    Test(int a, int b) {
        this->a = a; // Initialize class member a with parameter a
        this->b = b; // Initialize class member b with parameter b
        cout << "Parameterized Constructor called" << endl;
    }
    
    // Copy constructor
    Test(const Test& obj) {
        a = obj.a; // Copy value of a from the passed object
        b = obj.b; // Copy value of b from the passed object
        cout << "Copy Constructor called" << endl;
    }
    
    // Method to display values
    void display() const {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    // Create an object using the parameterized constructor
    Test obj(3, 4);
    obj.display(); // Display the values of obj

    // Create another object using the copy constructor
    Test obj1(obj);
    obj1.display(); // Display the values of obj1

    // Also be called as
    Test obj2 = obj;
    obj2.display();

    return 0;
}
