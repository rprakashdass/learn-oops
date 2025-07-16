#include "Product.h"
#include "ProductCatalog.h"
#include "Order.h"
#include "PaymentProcessor.h"

int main() {
    // Step 1: Create a product catalog
    ProductCatalog catalog;
    catalog.addProduct(Product("Idli", 20));
    catalog.addProduct(Product("Dosa", 30));
    catalog.addProduct(Product("Vada", 10));

    // Step 2: Create an order
    Order order1;
    order1.addItem("Idli", 3);
    order1.addItem("Dosa", 2);
    order1.addItem("Vada", 1);

    // Step 3: Process payment
    PaymentProcessor::processPayment(order1, catalog);

    return 0;
}
