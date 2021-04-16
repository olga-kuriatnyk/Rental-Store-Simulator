/**
 * ItemKey.cpp
 *  ItemKey class was created to store sorting atributes for each movie as an
 * object
 *
 * @author Olga Kuriatnyk
 */

#include "itemKey.h"

// explicit constructor
ItemKey::ItemKey(const string &keyTotal) { this->itemKey = keyTotal; }

// explicit constructor
ItemKey::ItemKey(const string &subKey1, const string &subKey2) {
  this->itemKey = subKey1 + " " + subKey2;
}

// @return item key
string ItemKey::getItemKey() const { return itemKey; }

// @return true if this < then other
bool ItemKey::operator<(const ItemKey &other) const {
  return this->itemKey < other.itemKey;
}

// @return true if objects are equal
bool ItemKey::operator==(const ItemKey &other) const {
  return (this->itemKey == other.itemKey);
}