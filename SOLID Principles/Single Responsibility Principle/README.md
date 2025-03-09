# Applying Single Responsibility Principle (SRP) in C++

## What is SRP?
The **Single Responsibility Principle (SRP)** states that a class should have only **one reason to change**.
This ensures better maintainability, scalability, and separation of concerns.

## How This Code Follows SRP:

### 1️⃣ Product Class (Single Responsibility: Represents a Product)
- Stores product details (name & price).
- Does **not** handle storage or retrieval.

### 2️⃣ ProductCatalog Class (Single Responsibility: Manages Product Storage)
- Stores products in a catalog.
- Allows retrieval of product prices.
- Handles product availability checks.

### 3️⃣ Order Class (Single Responsibility: Handles Order Management)
- Creates orders.
- Stores ordered items.
- Does **not** validate or process payments.

### 4️⃣ PaymentProcessor Class (Single Responsibility: Handles Payments)
- Calculates total order price.
- Processes payment.
- Does **not** modify orders or validate them.

## Advantages of SRP in this Code:
✅ Improved Maintainability → Each class has a clear role.  
✅ Scalability → Easy to extend functionality without breaking existing code.  
✅ Better Readability → Each class is easy to understand and debug.  
✅ Reduced Dependencies → No unnecessary coupling between unrelated tasks.  

## 🚀 Execution:
```sh
g++ main.cpp -o program
./program
```

### **Benefits of This SRP Refactor:**
1. **Each class has a single responsibility.**  
2. **Modifications to one part don’t affect others.**  
3. **Easier debugging and testing.**  
4. **Better separation of concerns.**  
