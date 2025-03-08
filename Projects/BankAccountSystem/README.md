# Bank Account System in C++

Managing bank accounts is a fundamental application of Object-Oriented Programming (OOP). In this article, we will walk through a **Bank Account System** implemented in C++, demonstrating key OOP concepts such as **encapsulation, constructors, private and public access specifiers, and error handling**.

---

## **1. Overview**

The system provides the following functionalities:
- Account creation with a **unique account number**.
- **Depositing and withdrawing** money with validation.
- Checking account balance.
- Displaying customer details.

Key OOP Features Used:
- **Encapsulation** (private and public data members and methods)
- **Constructors** (to initialize values at object creation)
- **Static Variables** (for generating unique account numbers)
- **Error Handling** (for invalid transactions)

---

## **2. Code Implementation**

### **Header Files and Global Variables**
```cpp
#include <iostream>
#include <string>
using namespace std;

static int unique_id = 1;
```
- `iostream` is included for input-output operations.
- `string` is used for storing customer names.
- `unique_id` is a **static variable** that ensures each account gets a unique ID.

---

### **3. Defining Messages for Errors and Success**
```cpp
const string SUCCESS_WITHDRAW = "Successfully withdrawned";
const string SUCCESS_DEPOSIT = "Successfully deposited";
const string SUCCESS_ACTIVATION = "Successfully activated";
const string ERROR_INVALID_AMOUNT = "Invalid amount";
const string ERROR_INSUFFICIENT_AMOUNT = "Insufficient amount";
```
- Predefined **constants** improve code readability and avoid hardcoded error messages.

---

### **4. Utility Function for Displaying Messages**
```cpp
void printCommand(int statusCode, string message) {
    string design(message.size() + 10, '=');
    cout << design << endl;
    if (statusCode) cout << "Error : ";
    else cout << "SUCCESS : ";
    cout << message << endl;
    cout << design << endl;
}
```
- This function displays error or success messages in a **formatted way**, improving UX.

---

### **5. The `BankAccount` Class**

#### **Class Definition**
```cpp
class BankAccount {
private:
    string customerName;
    long long accountNumber;
    int balance;
```
- **Encapsulation:** The `customerName`, `accountNumber`, and `balance` are private to ensure data security.

#### **Constructor and Account Initialization**
```cpp
public:
    BankAccount(string name) : customerName(name), balance(0) {
        setAccountNumber();
    }

    void setAccountNumber() {
        this->accountNumber = unique_id;
        unique_id++;
        printCommand(0, SUCCESS_ACTIVATION);
    }
```
- **Constructor:** Assigns the account holder’s name and initializes the balance to zero.
- **Static ID Allocation:** `unique_id` is used to generate a **unique account number** for each customer.

#### **Transaction Methods**
```cpp
    int verifAmount(int amount) {
        return (amount > 0);
    }
```
- **Helper function** to validate that the transaction amount is positive.

#### **Withdraw Money**
```cpp
    void withdraw(int amount) {
        if (balance <= 0 || balance < amount) {
            printCommand(1, ERROR_INSUFFICIENT_AMOUNT);
            return;
        }
        if (!verifAmount(amount)) {
            printCommand(1, ERROR_INVALID_AMOUNT);
            return;
        }
        this->balance -= amount;
        printCommand(0, SUCCESS_WITHDRAW);
    }
```
- Checks if the balance is sufficient before processing the withdrawal.
- Displays appropriate error messages if the conditions are not met.

#### **Deposit Money**
```cpp
    void deposit(int amount) {
        if (!verifAmount(amount)) {
            printCommand(1, ERROR_INVALID_AMOUNT);
            return;
        }
        this->balance += amount;
        printCommand(0, SUCCESS_DEPOSIT);
    }
```
- Ensures only valid deposits (positive amounts) are accepted.

#### **Check Balance and Show Account Details**
```cpp
    void getBalance() const {
        cout << "Current Balance is " << this->balance << endl;
    }

    void showDetails() const {
        cout << "Customer Name : " << customerName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance : " << balance << endl;
    }
};
```
- `getBalance()` prints the current balance.
- `showDetails()` provides account information.

---

### **6. Main Function and Sample Execution**
```cpp
int main() {
    BankAccount account1("Prakash");
    account1.deposit(5000);
    account1.withdraw(1000);
    account1.getBalance();
    account1.showDetails();

    cout << endl;

    BankAccount account2("Raja");
    account2.showDetails();
    account2.deposit(500);
    account2.withdraw(1000);
    account2.getBalance();
    account2.showDetails();
    return 0;
}
```
- Creates two bank accounts (`account1` and `account2`).
- Demonstrates deposit, withdrawal, and balance checking.

---

## **7. Expected Output**
```
=============================
SUCCESS : Successfully activated
=============================
=============================
SUCCESS : Successfully deposited
=============================
=============================
SUCCESS : Successfully withdrawned
=============================
Current Balance is 4000
Customer Name : Prakash
Account Number : 1
Current Balance : 4000

=============================
SUCCESS : Successfully activated
=============================
Customer Name : Raja
Account Number : 2
Current Balance : 0
=============================
SUCCESS : Successfully deposited
=============================
=============================
Error : Insufficient amount
=============================
Current Balance is 500
Customer Name : Raja
Account Number : 2
Current Balance : 500
```

---

## **8. Conclusion**

This project demonstrated an **OOP-based Bank Account System** in C++. It implemented key features such as **account creation, deposit, withdrawal, and balance checking** while ensuring **error handling and structured output formatting**.

### **Key Takeaways:**
- **Encapsulation** protects account details.
- **Constructors** ensure proper initialization.
- **Static variables** provide unique account numbers.
- **Error handling** prevents invalid transactions.

This serves as a strong foundation for a real-world banking system. Future enhancements can include **file handling for persistent storage** and **multithreading for concurrent transactions**.
