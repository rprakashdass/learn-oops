# Interface Segregation Principle (ISP) — Explained with Code and Interview Focus (C++)

This repository demonstrates the **Interface Segregation Principle (ISP)** from the SOLID principles using modern C++. It's structured to help software engineers, especially those preparing for system design and object-oriented interviews, understand and apply the principle practically and theoretically.

---

## What is ISP?

The **Interface Segregation Principle** states:

> "Clients should not be forced to depend upon interfaces that they do not use."

### Real Meaning:
When you have an interface (abstract class in C++) that contains multiple unrelated methods, and not all derived classes use all those methods, it's a sign to break the interface into smaller, more specific ones.

---

## How to Implement ISP in C++

1. **Identify Responsibilities**:
   Break large interfaces (classes with many virtual functions) into smaller ones that are specific to client needs.

2. **Use Composition**:
   Favor composing objects with smaller roles over large inheritance trees.

3. **Design with Role-based Interfaces**:
   Think in terms of *what the object does*, not what *it is*. For example:
   - `IReadable`, `IWritable` instead of `IDataHandler`.

### Example Structure:
```cpp
class IReadable {
public:
    virtual void read() = 0;
};

class IWritable {
public:
    virtual void write() = 0;
};
````

Then compose or inherit only what’s needed.

---

## ❌ How to Avoid Violating ISP

* Don't make "fat" base classes with too many responsibilities.
* Don't use inheritance just to reuse code — prefer interfaces with clear purpose.
* Don’t create abstract base classes where not all subclasses can fully implement the interface.
* Watch for dummy or empty method implementations — its a red flag.

---

## 📁 Files in This Repo

| File                    | Purpose                                                                                              |
| ----------------------- | ---------------------------------------------------------------------------------------------------- |
| `with_violation.cpp`    | Demonstrates an **ISP violation** where classes are forced to implement unused methods.              |
| `without_violation.cpp` | Shows a **correct ISP implementation** using segregated interfaces like `IReadable` and `IWritable`. |

---

## 💡 Key Advantages of ISP

* Higher cohesion and separation of concerns
* Increased maintainability
* Better testability
* Supports the Open/Closed Principle
* Avoids unnecessary re-compilation when changing a part of the interface

---

## 🔍 Interview-Focused Summary

| Area             | Insight                                                                         |
| ---------------- | ------------------------------------------------------------------------------- |
| **Design**       | Break down large interfaces into smaller, role-based ones.                      |
| **Inheritance**  | Don’t force derived classes to override irrelevant methods.                     |
| **Patterns**     | Often used with **Strategy**, **Adapter**, and **Composite** patterns.          |
---

## 📌 Most Common ISP Interview Questions

<details>
<summary><strong>1. What is the Interface Segregation Principle?</strong></summary>

A SOLID principle that states clients should not be forced to depend on interfaces they do not use. Instead, multiple specific interfaces are preferred over a single general-purpose interface.

</details>

<details>
<summary><strong>2. How is ISP different from SRP (Single Responsibility Principle)?</strong></summary>

* SRP is about **class responsibilities**.
* ISP is about **interface design**.
  They both promote cohesion, but at different levels.

</details>

<details>
<summary><strong>3. How do you identify an ISP violation in a system?</strong></summary>

Look for:

* Abstract classes with too many methods
* Subclasses that implement methods with empty bodies
* Objects relying on irrelevant methods from a dependency

</details>

<details>
<summary><strong>4. How do you apply ISP in C++ where there’s no native `interface` keyword?</strong></summary>

Use abstract base classes with pure virtual methods.

</details>

<details>
<summary><strong>5. Give a real-world analogy of ISP.</strong></summary>

A multi-function printer interface has `scan()`, `print()`, and `fax()`. If a device only prints, it shouldn't be forced to implement `scan()` and `fax()`. Split them into `IPrinter`, `IScanner`, and `IFax`.

</details>

<details>
<summary><strong>6. Can violating ISP lead to violating other SOLID principles?</strong></summary>

Yes. Violating ISP can cause SRP and OCP violations because your interface becomes too broad and inflexible, making future changes hard to manage.

</details>

<details>
<summary><strong>7. How does ISP relate to Dependency Inversion Principle (DIP)?</strong></summary>

Both emphasize abstraction. ISP ensures abstractions are small and focused, making it easier to invert dependencies in DIP.

</details>


<details>
<summary><strong>8. What are the consequences of violating ISP in large codebases?</strong></summary>

* Fragile systems
* Difficult testing and mocking
* More bugs due to unimplemented or irrelevant methods
* Harder onboarding and maintainability

</details>

<details>
<summary><strong>9. How do interface segregation and composition help scalability?</strong></summary>

Smaller, well-defined interfaces allow teams to build, test, and scale components independently. Composition encourages flexibility and reusability over rigid inheritance hierarchies.

</details>

---