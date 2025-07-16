#include "../../include/print.h"
#include <iostream>


class PaymentProcessor {
    virtual void processPayment(const std::string& amount) = 0;
};

class UPIPayment : PaymentProcessor {
    void processPayment(const std::string amount) {
        println("Payment is successfully processed through upi");
    }
};

class CashPayment : PaymentProcessor {
    void processPayment(const std::string amount) {
        std::runtime_error("Cash shouldnt support online payment");
    }
};