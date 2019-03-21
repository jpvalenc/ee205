#include "SupplyRunner.hpp"
#include "Ingredient.hpp"
#include "Storeroom.hpp"
#include <map>
#include <vector>

SupplyRunner::SupplyRunner(Storeroom& storeroom_) :
  storeroom(storeroom_)
 {}

std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
  std::map<std::string, int>::iterator it;
  std::vector<Ingredient> ingredientsSupplied;

  for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
    if (storeroom.find(it->first) == storeroom.end() || storeroom[it->first] < it->second) {
      throw "Not enough ingredients in the Storeroom.";
    }
  }
  
  for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
    storeroom[it->first] = storeroom[it->first] - 1;
    ingredientsSupplied.push_back(it->first);
  }

  return ingredientsSupplied;
}
