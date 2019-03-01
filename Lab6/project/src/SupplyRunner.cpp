#include "Storeroom.h"
#include <map>
#include <vector>

SupplyRunner::SupplyRunner(Storeroom& storeroom_) {
  this->storeroom = storeroom_;
}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
  std::map<std::string, int>::iterator it;
  std::vector<Ingredient> ingredientsSupplied;

  for (int it = ingredients.begin(); it != ingredients.end(); i++) {
    ingredientsSupplied.push_back(it->second);

    it++;
  }

  return ingredientsSupplied;
}