/**
 * customMap.h
 *  CustomMap class has implementation of hash table
 *
 * @authors Olga Kuriatnyk
 */

#ifndef CUSTOMMAP_H
#define CUSTOMMAP_H

#include "customer.h"
#include <cstring>
#include <iostream>
#include <list>

using namespace std;

// hash table
class CustomMap {
public:
  // creating an empty table
  CustomMap();

  // destructor
  ~CustomMap();

  // copy constructor not allowed
  CustomMap(const CustomMap &cusMap) = delete;

  // move not allowed
  CustomMap(CustomMap &&other) = delete;

  // assignment not allowed
  CustomMap &operator=(const CustomMap &other) = delete;

  // move assignment not allowed
  CustomMap &operator=(CustomMap &&other) = delete;

  // hash function for finding an index based on customerID
  int hashFunction(int id);

  // get customer object by ID
  Customer *getCustomerByID(int id);

  // function for adding a customer to the hashtable
  void addCustomer(int id, Customer *user);

private:
  // structure of list
  struct CustomerList {
    Customer *obj;
    CustomerList *next;
    int val;
  };

  // size of an array
  static const int HASH_GROUPS = 29;

  // array of lists for hash table
  CustomerList *array[HASH_GROUPS] = {};
};

#endif