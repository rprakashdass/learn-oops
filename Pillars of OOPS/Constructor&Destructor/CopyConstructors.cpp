#include <iostream>
using namespace std;

class Test {
public:
    int x, y;

    // Default constructor
    Test() {
        // Initializes x and y to 0 and prints a message
        x = 0;
        y = 0;
        cout << "Do nothing" << endl;
    }

    // Parameterized constructor
    Test(int a, int b) {
        // Initializes x and y with the provided values and prints them
        x = a;
        y = b;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "Parametrized constructor called x = " << x << " y = " << y << endl;
    }

    // Copy constructor
    Test(const Test& obj) {
        // Copies x and y from the existing object and increments them
        x = obj.x;
        y = obj.y;
        cout << "Copy constructor called x = " << ++x << " y = " << ++y << endl;
    }

    // Function to display values of x and y
    void display() {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int main() {
    // Create an object A with values 3 and 4
    Test A(3, 4);

    // Create an object B by copying object A
    // This will call the copy constructor
    Test B(A);

    // Create an object C using the default constructor
    Test C;

    // Assign values from object B to object C
    // This uses the default assignment operator (not explicitly defined)
    C = B;

    // Display the values of A, B, and C
    cout << "Values of A:" << endl;
    A.display();

    cout << "Values of B:" << endl;
    B.display();

    cout << "Values of C:" << endl;
    C.display();

    return 0;
}
