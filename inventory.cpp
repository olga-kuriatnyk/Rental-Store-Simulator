/**
 * Inventory.cpp
 *  Inventory class holds a map with all movies in the store.
 *
 * @author Olga Kuriatnyk
 */

#include "inventory.h"

// destructor
Inventory::~Inventory() {
  auto itr = inventory.begin();
  while (!inventory.empty()) {
    auto i = (*itr).second.begin();
    while (!(*itr).second.empty()) {
      delete *i;
      (*itr).second.erase(i);
      i = (*itr).second.begin();
    }
    inventory.erase((*itr).first);
    itr = inventory.begin();
  }
}

// insert new item to inventory map
void Inventory::insert(Movie *item) {
  char movieT = item->getMovieType();
  if (inventory.find(movieT) == inventory.end()) {
    vector<Movie *> emptyVector;
    inventory.emplace(movieT, emptyVector);
  }
  inventory[movieT].push_back(item);
}

// retrieve item, if not found @return nullptr
Movie *Inventory::retrieve(char movieType, const ItemKey &itemKey) {
  if (inventory.find(movieType) != inventory.end()) {
    int size = inventory.find(movieType)->second.size();
    for (int i = 0; i < size; i++) {
      if (inventory.find(movieType)->second[i]->getItemKey() == itemKey) {
        return inventory.find(movieType)->second[i];
      }
    }
  }
  return nullptr;
}

// sort items in the inventory
void Inventory::sortItems() {
  for (auto &itr : inventory) {
    sortByAtributes(itr.second);
  }
}

// to print inventory
void Inventory::printInventory() {
  cout << "\n***INVENTORY***" << endl;
  for (auto &itr : inventory) {
    for (auto &i : (itr).second) {
      i->printMovie();
    }
  }
  cout << endl;
}

// helper function for sorting elements insive the vector
void Inventory::sortByAtributes(vector<Movie *> &items) {
  sort(items.begin(), items.end(),
       [](Movie *p, Movie *q) { return p->getItemKey() < q->getItemKey(); });
}