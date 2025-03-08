# **Understanding OOP with a Shapes Hierarchy in C++**

Object-Oriented Programming (OOP) helps us design real-world models effectively in programming. A classic example of using OOP concepts is building a **Shapes Hierarchy**, where different geometric shapes like **Circle, Rectangle, and Triangle** inherit from a common base class.

In this article, we’ll explore how **abstraction, polymorphism, and inheritance** work in C++ using a **shapes-based hierarchy**.

---

## **1. Designing the Base Class - Shapes**

Every shape has two key properties:

- **Area**
- **Perimeter**

Since each shape has a different formula for calculating these values, we define a **base class with pure virtual functions** that enforce a contract for subclasses to implement them.

```cpp
class Shapes {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shapes() {}
};

```

### **Key Features:**

✅ `area()` and `perimeter()` are **pure virtual functions**, making `Shapes` an **abstract class**.

✅ The **destructor is virtual**, ensuring proper cleanup in derived classes.

---

## **2. Implementing Specific Shapes**

Now, let’s implement different shapes that inherit from the `Shapes` class.

### **a) Circle Class**

```cpp
class Circle : public Shapes {
private:
    int radius;
public:
    Circle(int radius) : radius(radius) {}
    double area () const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return (2 * M_PI * radius);
    }
};

```

🔹 Uses `M_PI` from `<cmath>` for accuracy.

🔹 Implements its own **area** and **perimeter** calculations.

---

### **b) Rectangle Class**

```cpp
class Rectangle : public Shapes {
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

```

🔹 Simple implementation with length and width.

🔹 Overrides the base class methods.

---

### **c) Triangle Class**

```cpp
class Triangle : public Shapes {
private:
    int base, height, side1, side2, side3;
public:
    Triangle(int base, int height, int side1, int side2, int side3)
        : base(base), height(height), side1(side1), side2(side2), side3(side3) {}
    double area () const override {
        return (base * height) / 2.0;
    }
    double perimeter () const override {
        return side1 + side2 + side3;
    }
};

```

🔹 The class supports both **base-height-based area calculation** and **perimeter calculation** using side lengths.

**⚠️ Note:** Ensure all side values are initialized before calling `perimeter()`, as some constructors don’t include `side1`, `side2`, and `side3`.

---

## **3. Testing the Shape Hierarchy**

Now, let's create objects and test their functionality in `main()`.

```cpp
int main() {
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

```

### **Sample Output:**

```
Area of the circle is 78.5398
Perimeter of the circle is 31.4159
Area of the rectangle is 24
Perimeter of the rectangle is 20
Area of the triangle is 5
Perimeter of the triangle is 12

```

---

## **4. Key Takeaways from the Shapes Hierarchy**

✅ **Abstraction** - The `Shapes` class enforces area and perimeter calculations for all derived classes.

✅ **Polymorphism** - The same method names (`area()`, `perimeter()`) behave differently in each subclass.

✅ **Encapsulation** - Data members are kept private for data safety.

✅ **Inheritance** - `Circle`, `Rectangle`, and `Triangle` extend `Shapes`, reusing the interface.