#include<iostream>
#include<string>
using namespace std;

// Abstract Class for Payment Processing
class PaymentProcessor {
public:
    virtual void processPayment(double amount) const = 0;
    virtual ~PaymentProcessor() {};
};

// Cash Payment Implementation
class CashPayment : public PaymentProcessor {
public:
    void processPayment(double amount) const override {
        cout << "Cash payment is processing for amount " << amount << endl;
    }
};

// UPI Payment Implementation
class UPIPayment : public PaymentProcessor {
public:
    void processPayment(double amount) const override {
        cout << "UPI payment is processing for amount " << amount << endl;
    }
};

// Function to Process Any Payment Method
void processTransaction(const PaymentProcessor& paymentMethod, double amount) {
    paymentMethod.processPayment(amount);
}

int main() {
    double amount = 785.012;
    CashPayment cashPayment;
    UPIPayment upiPayment;

    // Processing transactions using different payment methods
    processTransaction(cashPayment, amount);
    processTransaction(upiPayment, amount);

    //can add any type of payment method
    return 0;
}
