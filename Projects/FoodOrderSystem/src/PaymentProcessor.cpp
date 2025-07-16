#include "PaymentProcessor.h"

double PaymentProcessor::calculateTotalAmount(const Order& order, const ProductCatalog& catalog) {
    double total = 0;
    for (const auto& item : order.getItems()) {
        std::string productName = item.first;
        int quantity = item.second;
        total += catalog.getProductPrice(productName) * quantity;
    }
    return total;
}

void PaymentProcessor::processPayment(const Order& order, const ProductCatalog& catalog) {
    double totalAmount = calculateTotalAmount(order, catalog);
    std::cout << "Processing payment of Rs." << totalAmount << " for Order ID: " << order.getOrderId() << std::endl;
}
