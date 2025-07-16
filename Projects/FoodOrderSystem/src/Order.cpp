#include "Order.h"

int Order::ORDER_ID = 111;

Order::Order() : order_id(ORDER_ID++) {}

void Order::addItem(const std::string& item, int quantity) {
    items.push_back(std::make_pair(item, quantity));
}

int Order::getOrderId() const {
    return order_id;
}

const std::vector<std::pair<std::string, int>>& Order::getItems() const {
    return items;
}
