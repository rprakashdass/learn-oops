#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include <iostream>
#include "Order.h"
#include "ProductCatalog.h"

class PaymentProcessor {
public:
    static double calculateTotalAmount(const Order& order, const ProductCatalog& catalog);
    static void processPayment(const Order& order, const ProductCatalog& catalog);
};

#endif
