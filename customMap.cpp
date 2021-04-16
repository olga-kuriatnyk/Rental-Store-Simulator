/**
 * customMap.cpp
 *  CustomMap class has implementation of hash table
 *
 * @author Olga Kuriatnyk
 */

#include "customMap.h"

// creating an empty table
CustomMap::CustomMap() {
  for (auto &i : array) {
    i = nullptr;
  }
}

// destructor
CustomMap::~CustomMap() {
  for (auto &i : array) {
    if (i != nullptr) {
      CustomerList *x = i;
      while (i != nullptr) {
        i = i->next;
        delete x->obj;
        delete x;
        x = nullptr;
        x = i;
      }
    }
  }
}

// hash function for finding an index based on customerID
int CustomMap::hashFunction(int id) { return id % HASH_GROUPS; }

// get customer object by ID
Customer *CustomMap::getCustomerByID(int id) {
  int position = hashFunction(id);
  if (array[position] != nullptr) {
    CustomerList *curr = array[position];
    while (curr != nullptr) {
      if (curr->val == id) {
        return curr->obj;
      }
      curr = curr->next;
    }
  }
  return nullptr;
}

// function for adding a customer to the hashtable
void CustomMap::addCustomer(int id, Customer *user) {
  int position = hashFunction(id);
  auto *placeholder = new CustomerList;
  placeholder->val = id;
  placeholder->obj = user;
  placeholder->next = nullptr;
  if (array[position] != nullptr) {
    CustomerList *curr = array[position];
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = placeholder;
  } else {
    placeholder->next = array[position];
    array[position] = placeholder;
  }
}