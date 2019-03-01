#include "Cook.hpp"

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) {
  this->runner = runner_;
  this->kitchen = kitchen_;
}

void Cook::prepare_dish(
  std::stack<Order>& orders,
  std::queue<std::pair<std::size_t,Dish>>& finished_dishes) {
    Order order = orders.top().get_items();

    for (int i = 0; i < order.size(); i++) {
      IngredientMap ingredients = recipies.find(order[i]);

      std::vector<Ingredient> supplies = get_ingredients(ingredients);

      Dish dish = Kitchen::prepare_dish(ingredients);

      finished_dishes.push(order.get_id(), dish);
    }
  }
