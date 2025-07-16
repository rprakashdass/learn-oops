#include <iostream>
#include <string>

class OnlinePaymentProcessor {
public:
    virtual void processPayment(const std::string& amount) = 0;
    virtual ~OnlinePaymentProcessor() = default;
};

class OfflinePaymentProcessor {
public:
    virtual void processPayment(const std::string& amount) = 0;
    virtual ~OfflinePaymentProcessor() = default;
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


void completeOnlinePayment(OnlinePaymentProcessor* pay, const std::string& amount) {
    pay->processPayment("100");
}

void completeOfflinePayment(OfflinePaymentProcessor* pay, const std::string& amount) {
    pay->processPayment("100");
}

int main (){

    UPIPayment pay;
    completeOnlinePayment(&pay, "100");

    CashPayment cash;
    completeOfflinePayment(&cash, "200");
}