#include <iostream>
using namespace std;

// Define the Test class
class Test {
public:
    int obj_id = 0; // Data member to hold the object ID

    // Constructor of Test class
    Test() {
        cout << "Constructor called for " << obj_id << endl;
    }

    // Destructor of Test class
    ~Test() {
        cout << "Destructor called for " << obj_id << endl;
    }
};

int main() {
    // Create an object of Test class named obj1
    Test obj1;
    obj1.obj_id = 1; // Set the obj_id of obj1 to 1

    // Start a new block scope
    if (1) {
        // Create an object of Test class named obj2
        Test obj2;
        obj2.obj_id = 2; // Set the obj_id of obj2 to 2

        // Start another new block scope
        if (1) {
            // Create an object of Test class named obj3
            Test obj3;
            obj3.obj_id = 3; // Set the obj_id of obj3 to 3
        } // End of the inner block scope, obj3 is destroyed here

    } // End of the outer block scope, obj2 is destroyed here

    // End of main function, obj1 is destroyed here

    return 0;
}
