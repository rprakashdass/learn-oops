#include "ProductCatalog.h"

void ProductCatalog::addProduct(const Product& product) {
    catalog[product.getName()] = product.getPrice();
}

bool ProductCatalog::isProductAvailable(const std::string& productName) const {
    return catalog.find(productName) != catalog.end();
}

double ProductCatalog::getProductPrice(const std::string& productName) const {
    return catalog.at(productName);
}