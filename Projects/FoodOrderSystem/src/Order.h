#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>

class Order {
private:
    int order_id;
    std::vector<std::pair<std::string, int>> items;
    static int ORDER_ID;
public:
    Order();
    void addItem(const std::string& item, int quantity);
    int getOrderId() const;
    const std::vector<std::pair<std::string, int>>& getItems() const;
};

#endif // ORDER_H