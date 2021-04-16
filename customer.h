/**
 * Customer.h
 *  Customer class includes customerID, lastName, string firstName,
 *  and vector<string> to store customer history.
 *
 * @author Olga Kuriatnyk
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "movie.h"

using namespace std;

class Customer {
public:
  // explicit constructor
  explicit Customer(int id);

  // default destuctor
  ~Customer() = default;

  // copy constructor not allowed
  Customer(const Customer &c) = delete;

  // move not allowed
  Customer(Customer &&other) = delete;

  // assignment not allowed
  Customer &operator=(const Customer &other) = delete;

  // move assignment not allowed
  Customer &operator=(Customer &&other) = delete;

  // @return user ID
  int getID() const;

  // @return user last name
  string getLastName() const;

  // @return user first name
  string getFirstName() const;

  // reads the line from the file and sets the values to this object
  void read(istream &is);

  // add note to the customers' history
  void insertHistory(const string &str);

  // @return true if customer has borrowd the movie
  bool findHistory(const string &str);

  // print customer history
  void printCustomerHistory() const;

private:
  int customerID;
  string lastName;
  string firstName;

  // to store customer history
  vector<string> customerHistory;
};

class CustomerFactory {
public:
  // @return new Customer object
  static Customer *create(int id) {

    if (id >= 1000 && id <= 9999) {
      return new Customer(id);
    }
    return nullptr;
  }
};
#endif
