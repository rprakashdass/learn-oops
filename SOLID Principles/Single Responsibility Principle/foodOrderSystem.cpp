// report generator
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

static int ORDER_ID = 111;

// Product Class: Represents a product (SRP: Only holds product data)
class Product {
private:
    string name;
    double price;
public:
    Product(string name, double price) : name(name), price(price) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
};

// ProductCatalog Class: Manages product storage (SRP: Only catalog operations)
class ProductCatalog {
private:
    unordered_map<string, double> catalog;
public:
    void addProduct(const Product& product) {
        catalog[product.getName()] = product.getPrice();
    }
    bool isProductAvailable(const string& productName) const {
        return catalog.find(productName) != catalog.end();
    }
    double getProductPrice(const string& productName) const {
        return catalog.at(productName);
    }
};


// Order Class: Manages order creation (SRP: Order-related operations only)
class Order {
    private:
    int order_id;
    vector<pair<string, int>> items;
    public:
    Order() : order_id(ORDER_ID++) {}
    void addItem(const string& item, int quantity) {
        items.push_back(make_pair(item, quantity));
    }
    int getOrderId() const { return order_id; }
    const vector<pair<string, int>>& getItems() const { return items; }
};

// PaymentProcessor Class: Handles payment (SRP: Only payment-related tasks)
class PaymentProcessor{
public:
    static double calculateTotalAmount(const Order& order, const ProductCatalog& catlog){
        double total = 0;
        for(const auto& item: order.getItems()){
            string productName = item.first;
            int quantity = item.second;
            total += catlog.getProductPrice(productName) * quantity;
        }
        return total;
    }
    static void processPayment(const Order& order, const ProductCatalog& catlog){
        double totalAmount = calculateTotalAmount(order, catlog);
        cout << "Processing payment of Rs." << totalAmount << " for Order ID: " << order.getOrderId() << endl;
    }
};

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