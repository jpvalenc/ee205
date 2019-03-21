#include <iostream>
#include <vector>
#include <string>

#include "Customer.hpp"
#include "Cashier.hpp"

Cashier::Cashier(double money_) {
  this->money = money_;
}

double Cashier::get_money() const {
  return this->money;
}

void Cashier::serve_customer(
std::queue<Customer>& line,
std::stack<Order>& orders) {
  // Get latest customer and pop off queue
  Customer customer = line.front();
  line.pop();

  // Get input of items
  std::string orderItems;
  std::cout << "Enter the items you want to order:" << std::endl;
  std::cin >> orderItems;

  // Split by space, push to vector
  std::vector<std::string> split;

  for (char& c : orderItems) {
    std::string string;

    if (c != ' ') {
      string = string + c;
    } else if (c == ' ' || c == ',') {
      split.push_back(string);
    }
  }

  // If index is even, push to quantities
  // If index is odd, push to items
  std::vector<std::string> quantities;
  std::vector<std::string> items;

  for (unsigned i = 0; i < split.size(); i++) {
    if (i % 2 == 0) { // even
      quantities.push_back(split[i]);
    } else if (i % 2 != 0) {
      items.push_back(split[i]);
    }
  }

  std::vector<std::string> itemsWithQuantities;

  for (unsigned i = 0; i < items.size(); i++) {
    for (unsigned j = 0; i < std::stoi(quantities[i]); i++) {
      itemsWithQuantities.push_back(items[i]);
    }
  }

  double orderCost = calculate_order_cost(itemsWithQuantities);

  if (customer.get_money() >= orderCost) {
    customer.charge_money(orderCost);
  } else {
    customer.expel();
  }

  // Create order and pass in items
  Order order(orders.size(), items);

}