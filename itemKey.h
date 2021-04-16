/**
 * ItemKey.h
 *  ItemKey class was created to store sorting atributes for each movie as an
 * object
 *
 * @author Olga Kuriatnyk
 */

#ifndef ITEMKEY_H
#define ITEMKEY_H

#include <string>

using namespace std;

class ItemKey {
public:
  // default constructor
  ItemKey() = default;

  // explicit constructor
  explicit ItemKey(const string &keyTotal);

  // explicit constructor
  explicit ItemKey(const string &subKey1, const string &subKey2);

  // destructor
  ~ItemKey() = default;

  // copy constructor not allowed
  ItemKey(const ItemKey &key) = default;

  // move not allowed
  ItemKey(ItemKey &&other) = default;

  // assignment not allowed
  ItemKey &operator=(const ItemKey &other) = default;

  // move assignment not allowed
  ItemKey &operator=(ItemKey &&other) = default;

  // @return item key
  string getItemKey() const;

  // @return true if this < then other
  bool operator<(const ItemKey &other) const;

  // @return true if objects are equal
  bool operator==(const ItemKey &other) const;

private:
  // to store sortingAttribute in string
  string itemKey;
};
#endif