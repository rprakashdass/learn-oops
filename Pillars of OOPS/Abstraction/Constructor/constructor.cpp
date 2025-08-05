/*
An abstract class can still have its own data members (fields, attributes).
The constructor is the proper place to initialize these members, especially if they are private or protected.

C++ ensures, in inheritance child class method is called next to the base class constructor being called.

*/

#include<iostream>
#include<string>

using namespace std;

class Shape {
protected:
    string shapeName;
public:
    Shape(string shapeName) : shapeName(shapeName) {
        std::cout << "Shape constructor called for: " << shapeName << std::endl;
    }
    void printName() const {
        std::cout << "My name is " << shapeName << std::endl;
    }
    virtual double getArea() = 0;

    // virtual destructor
    virtual ~Shape() {
        std::cout << "Shape destructor for '" << shapeName << "' called." << std::endl;
    }
};

class Circle : public Shape{
private:
    int radius;
public:
    // it is compulsory to call abstract class constructor
    Circle(int radius) : Shape("circle") , radius(radius) {
        cout << "Circle shape constructor is called\n";
    }
    double getArea() override {
        return 3.14 * radius * radius;
    }
    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }
};

int main() {
    int radius = 5;
    Shape *circle = new Circle(radius);
    circle->printName();
    cout << circle->getArea() << endl;
    delete circle; // deletes Shape as well as circle class destructor
    return 0;
}