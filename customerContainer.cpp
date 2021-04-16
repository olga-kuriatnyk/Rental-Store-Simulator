/**
 * CustomerContainer.cpp
 *  CustomerContainer class holds a list of customert in CustomMap(hashTable)
 *
 * @author Olga Kuriatnyk
 */

#include "customerContainer.h"

// insert new Customer to the list of customers
void CustomerContainer::insert(Customer *customer) {
  customersList.addCustomer(customer->getID(), customer);
}

// @return true if id is not used for another customer
// and it's 4 digits
bool CustomerContainer::validID(int id) {
  return ((customersList.getCustomerByID(id) == nullptr) &&
          (id >= 1000 && id <= 9999));
}

// retrieve customer from the list
// @return pointer to a customer, or nullptr if not found
Customer *CustomerContainer::retrieve(int id) {
  if (customersList.getCustomerByID(id) != nullptr) {
    return customersList.getCustomerByID(id);
  }
  return nullptr;
}