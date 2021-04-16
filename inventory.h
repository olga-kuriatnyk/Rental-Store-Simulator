/**
 * Inventory.h
 *  Inventory class holds a map with all movies in the store.
 *
 * @author Olga Kuriatnyk
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "movie.h"

class Inventory {
public:
  // function to get an Instance of all inventory
  static Inventory &getInstance() {
    static Inventory instance;
    return instance;
  }

  // constructor
  Inventory() = default;

  // copy not allowed
  Inventory(const Inventory &other) = delete;

  // move not allowed
  Inventory(Inventory &&other) = delete;

  // assignment not allowed
  Inventory &operator=(const Inventory &other) = delete;

  // move assignment not allowed
  Inventory &operator=(Inventory &&other) = delete;

  // destructor
  ~Inventory();

  // insert new item to inventory map
  void insert(Movie *item);

  // retrieve item, if not found @return nullptr
  Movie *retrieve(char movieType, const ItemKey &itemKey);

  // sort items in the inventory
  void sortItems();

  // to print inventory
  void printInventory();

private:
  static Inventory *instance;

  // key - movieType, value - vector of items
  map<char, vector<Movie *>, greater<char> > inventory;

  // helper function for sorting elements insive the vector
  void sortByAtributes(vector<Movie *> &items);
};
#endif