#ifndef PRODUCTCATALOG_H
#define PRODUCTCATALOG_H

#include <unordered_map>
#include "Product.h"

class ProductCatalog {
private:
    std::unordered_map<std::string, double> catalog;
public:
    void addProduct(const Product& product);
    bool isProductAvailable(const std::string& productName) const;
    double getProductPrice(const std::string& productName) const;
};

#endif // PRODUCTCATALOG_H
