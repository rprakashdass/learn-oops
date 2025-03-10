# **Open/Closed Principle (OCP) in C++**

## **📌 Introduction**
The **Open/Closed Principle (OCP)** states that a class should be **open for extension** but **closed for modification**. This means we should be able to add new functionality without altering existing code.

This project demonstrates OCP using a **payment processing system**, where new payment methods can be added without modifying existing code.

---

## **📌 Code Explanation**
This program follows **OCP** by defining a **base class** (`PaymentProcessor`) and using **polymorphism** to support different payment methods.

### **1️⃣ Base Class (Abstract)**
- `PaymentProcessor`: Defines a **pure virtual function** `processPayment()` that must be implemented by derived classes.

### **2️⃣ Concrete Implementations**
- `CashPayment`: Implements cash payment processing.
- `UPIPayment`: Implements UPI payment processing.

### **3️⃣ Processing Transactions**
- The `processTransaction()` function accepts any `PaymentProcessor` object and calls `processPayment()` dynamically.

### **4️⃣ Adding New Payment Methods**
- If a new payment method (e.g., **CreditCardPayment**) is required, we can simply **extend** the `PaymentProcessor` class without modifying existing code.

---

## **📌 How OCP is Applied Here?**
✅ **Closed for Modification** → No need to change existing classes when adding new payment methods.  
✅ **Open for Extension** → Simply create a new class inheriting from `PaymentProcessor`.  
✅ **Polymorphism Used** → The `processTransaction()` function works with any `PaymentProcessor` type.  

---

## **📌 How to Run the Code?**
### **1️⃣ Compile the Code**
```sh
g++ main.cpp -o payment_system
```

### **2️⃣ Run the Executable**
```sh
./payment_system
```

### **3️⃣ Expected Output**
```
Cash payment is processing for amount 785.012
UPI payment is processing for amount 785.012
```

---

## **📌 Extending the Code**
To add a new payment method (**e.g., Credit Card Payment**), just create a new class:
```cpp
class CreditCardPayment : public PaymentProcessor {
public:
    void processPayment(double amount) const override {
        cout << "Credit Card payment is processing for amount " << amount << endl;
    }
};
```
Now, you can use:
```cpp
CreditCardPayment creditCard;
processTransaction(creditCard, amount);
```
No changes needed in existing code! 🎉

---

## **📌 Summary**
This implementation follows **OCP** by making it easy to extend functionalities without modifying the existing logic.  
New payment methods can be added **without modifying** `processTransaction()`, ensuring **scalability** and **maintainability**.