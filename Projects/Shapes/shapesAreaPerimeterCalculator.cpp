#include<iostream>
#include<cmath>

class Shapes{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shapes(){}
};

class Circle : public Shapes{
private:
    int radius;
    double PI = M_PI;
public:
    Circle(int radius) : radius(radius) {}
    double area () const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return (2 * PI * radius);
    }
};

class Rectangle : public Shapes{
private:
    int length, width;
public:
    Rectangle(int length, int width) : length(length), width(width) {}
    double area () const override {
        return length * width;
    }
    double perimeter () const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shapes{
private:
    int base, height, side1, side2, side3;
public:
    Triangle(int base, int height, int side1, int side2, int side3)
    : base(base), height(height), side1(side1), side2(side2), side3(side3) {}

    double area () const override {
        return (base * height) / 2;
    }
    double perimeter () const override {
        return (side1 + side2 + side3);
    }
};

int main(){
    Circle circleObj(5);
    std::cout << "Area of the circle is " << circleObj.area() << std::endl;
    std::cout << "Perimeter of the circle is " << circleObj.perimeter() << std::endl;

    Rectangle rectangleObj(4, 6);
    std::cout << "Area of the rectangle is " << rectangleObj.area() << std::endl;
    std::cout << "Perimeter of the rectangle is " << rectangleObj.perimeter() << std::endl;

    Triangle triangleObj(5, 2, 3, 4, 5);
    std::cout << "Area of the triangle is " << triangleObj.area() << std::endl;
    std::cout << "Perimeter of the triangle is " << triangleObj.perimeter() << std::endl;

    return 0;
}