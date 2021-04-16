/**
 * CustomerContainer.h
 *  CustomerContainer class holds a list of customert in CustomMap(hashTable)
 *
 * @author Olga Kuriatnyk
 */

#ifndef CUSTOMERCONTAINER_H
#define CUSTOMERCONTAINER_H

#include "customMap.h"

using namespace std;

class CustomerContainer {
public:
  // get instance of this class
  static CustomerContainer &getInstance() {
    static CustomerContainer instance;
    return instance;
  }

  // constructor
  CustomerContainer() = default;

  // destructor
  ~CustomerContainer() = default;

  // copy constructor not allowed
  CustomerContainer(const CustomerContainer &c) = delete;

  // move not allowed
  CustomerContainer(CustomerContainer &&other) = delete;

  // assignment not allowed
  CustomerContainer &operator=(const CustomerContainer &other) = delete;

  // move assignment not allowed
  CustomerContainer &operator=(CustomerContainer &&other) = delete;

  // insert new Customer to the list of customers
  void insert(Customer *customer);

  // @return true if id is not used for another customer
  // and it's 4 digits
  bool validID(int id);

  // retrieve customer from the list
  // @return pointer to a customer, or nullptr if not found
  Customer *retrieve(int id);

private:
  static CustomerContainer *instance;

  CustomMap customersList;
};
#endif