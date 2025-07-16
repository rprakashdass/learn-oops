# Dependency Inversion Principle (DIP) — Explained with Keyboard Example in Modern C++

This repository demonstrates the **Dependency Inversion Principle (DIP)** from the SOLID principles using a clean and practical C++ example. It is tailored for developers preparing for system design or object-oriented programming interviews.

---

## What is DIP?

> "High-level modules should not depend on low-level modules. Both should depend on abstractions."

> "Abstractions should not depend on details. Details should depend on abstractions."

### Real Meaning:

High-level classes (like `Computer`) shouldn't directly rely on concrete implementations (like `WiredKeyboard` or `WirelessKeyboard`). Instead, they should interact with abstractions (interfaces like `Keyboard`). This ensures flexibility and extensibility.

---

## DIP in Action (C++ Style)

### Key Concepts

* **High-Level Module**: `Computer`
* **Low-Level Modules**: `WiredKeyboard`, `WirelessKeyboard`
* **Abstraction**: `Keyboard` interface

---

## Without DIP (Violation - Tightly Coupled)

```cpp
class Computer {
    WiredKeyboard keyboard;  // tightly coupled to a specific keyboard type
public:
    void start() {
        keyboard.connect();
    }
};
```

In this version:

* `Computer` is tightly coupled to `WiredKeyboard`
* You cannot plug in a `WirelessKeyboard` without modifying the `Computer` class
* Violates the **Open/Closed Principle** and **DIP**

---

## Benefits of Following DIP

| Benefit       | Explanation                                                                |
| ------------- | -------------------------------------------------------------------------- |
| Flexibility   | Easily switch from wired to wireless without changing the `Computer` class |
| Testability   | Inject mock keyboards during testing                                       |
| Low Coupling  | Reduces the ripple effect of changes                                       |
| Extendability | Add more keyboard types without modifying high-level code                  |

---

## Interview Summary

| Question                             | Answer                                                                   |
| ------------------------------------ | ------------------------------------------------------------------------ |
| What is DIP?                         | High-level modules should depend on abstractions                         |
| How does DIP differ from ISP or SRP? | DIP is about **relationships between layers**, not just responsibilities |
| How to implement DIP in C++?         | Use **abstract base classes** and **constructor injection**              |
| How does DIP help testing?           | You can inject mocks, stubs, or fakes in place of real implementations   |

---

## Real World Analogy

**Power Socket (Abstraction)**

* Devices (Laptops, Chargers) depend on **socket standards**, not on specific wall circuits.
* You can plug in different devices as long as they match the socket abstraction.
