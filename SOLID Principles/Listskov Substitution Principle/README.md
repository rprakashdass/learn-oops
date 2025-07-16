# Liskov Substitution Principle (LSP) - Interview-Oriented README

## 🔍 What is LSP?

**Liskov Substitution Principle (LSP)** is the 'L' in SOLID principles. It states:

> "If S is a subtype of T, then objects of type T may be replaced with objects of type S without altering any of the desirable properties of that program."

In simpler terms: **a subclass should behave properly in place of its superclass**. If substituting a subclass breaks the program logic, it violates LSP.

---

## ✅ Why LSP Matters (Especially for Interviews)

1. **Predictability**: Subtypes don't alter expected behavior.
2. **Maintainability**: Systems are easier to understand and extend.
3. **Polymorphism**: Achieved safely.
4. **Extending**: Allows developers to build on top of code with confidence.

---

## ❌ LSP Violation Example: Payment Processors

```cpp
class OnlinePaymentProcessor {
public:
    virtual void processPayment(const std::string& amount) = 0;
};

class OfflinePaymentProcessor {
public:
    virtual void processPayment(const std::string& amount) = 0;
};

class UPIPayment : public OnlinePaymentProcessor {
public:
    void processPayment(const std::string& amount) override {
        std::cout << "Payment of " << amount << " processed via UPI." << std::endl;
    }
};

class CashPayment : public OfflinePaymentProcessor {
public:
    void processPayment(const std::string& amount) override {
        std::cout << "Payment of " << amount << " processed in cash." << std::endl;
    }
};
```

🔴 Here, we have different base classes — this breaks substitutability. You can’t treat `CashPayment` as a general payment processor, making it harder to extend or reuse.

---

## ✅ LSP-Compliant Version

```cpp
class PaymentProcessor {
public:
    virtual void processPayment(const std::string& amount) = 0;
};

class UPIPayment : public PaymentProcessor {
public:
    void processPayment(const std::string& amount) override {
        std::cout << "Payment of " << amount << " processed via UPI." << std::endl;
    }
};

class CashPayment : public PaymentProcessor {
public:
    void processPayment(const std::string& amount) override {
        throw std::runtime_error("Cash should not support online payments.");
    }
};
```

🔸 This still violates LSP if `CashPayment` is used where online behavior is expected.

✅ The ideal fix? **Avoid designing subclasses that don’t fully support the parent’s contract.** Use Interface Segregation if needed.

---

## 🔧 How to Implement LSP Correctly

* Ensure **derived classes** override only behaviors they fully support.
* Avoid throwing unexpected exceptions in child classes.
* Use **interface segregation** to split incompatible responsibilities.
* Use **composition over inheritance** when behavior isn’t shared.

---

## ❓ Frequently Asked Interview Questions on LSP

### Q1. What is LSP and why is it important?

It ensures that a subclass can replace a base class without breaking the application’s logic.

### Q2. How do you identify an LSP violation?

Look for child classes that override methods to throw errors or behave differently than expected.

### Q3. Can you give a real-world example of LSP violation?

The Square–Rectangle problem and the PaymentProcessor (UPI vs Cash) are common examples.

### Q4. How is LSP related to interface segregation?

Sometimes violating LSP reveals that the base interface has too many responsibilities — which calls for ISP.

### Q5. How can composition help solve LSP issues?

By separating responsibilities into components instead of enforcing an "is-a" relationship that doesn’t fit behaviorally.

### Q6. Is throwing an exception in a derived class a violation?

Yes, if the base class doesn't throw and the child does — it's an LSP violation.

### Q7. Is LSP checked at compile-time?

No. LSP is about behavior — it's often detected through testing or design inspection.

### Q8. Is using abstract base classes helpful for LSP?

Yes — but they must be well-designed with minimal and cohesive responsibilities.

### Q9. How do you fix LSP violations in legacy code?

Refactor using interface segregation, delegation, or composition patterns.

### Q10. When should you avoid inheritance to preserve LSP?

When the derived class cannot honor the behavior contract of the base class.
