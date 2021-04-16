/**
 * Customer.cpp
 *  Customer class includes customerID, lastName, string firstName,
 *  and vector<string> to store customer history.
 *
 * @author Olga Kuriatnyk
 */

#include "customer.h"

// explicit constructor
Customer::Customer(int id) { this->customerID = id; }

// @return user ID
int Customer::getID() const { return this->customerID; }

// @return user last name
string Customer::getLastName() const { return this->lastName; }

// @return user first name
string Customer::getFirstName() const { return this->firstName; }

// reads the line from the file and sets the values to this object
void Customer::read(istream &is) { is >> this->firstName >> this->lastName; }

// add note to the customers' history
void Customer::insertHistory(const string &str) {
  this->customerHistory.push_back(str);
}

// @return true if customer has borrowd the movie
bool Customer::findHistory(const string &str) {
  for (const auto &i : customerHistory) {
    if (i == str) {
      return true;
    }
  }
  return false;
}

// print customer history
void Customer::printCustomerHistory() const {
  cout << "History Customer [" << this->getFirstName() << " "
       << this->getLastName()
       << "] ID [" + to_string(customerID) + "] : " << endl;
  if (customerHistory.empty()) {
    cout << "\tNo history." << endl;
  } else {
    for (const auto &i : customerHistory) {
      cout << "\t" << i << endl;
    }
  }
}