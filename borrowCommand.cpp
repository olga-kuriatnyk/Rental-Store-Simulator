/**
 * BorrowCommand.cpp
 * BorrowCommand is a child of Command class.
 * Borrow (denoted as ‘B’): (stock – 1) for each item borrowed.
 *
 * @author Olga Kuriatnyk
 */

#include "borrowCommand.h"

// explicit constructor
BorrowCommand::BorrowCommand(const char &commandType) {
  this->commandType = commandType;
  this->mediaType = ' ';
  this->movieType = ' ';
  this->customerID = 0;
}

// destructor
BorrowCommand::~BorrowCommand() = default;

// read the command string load into customerID and key
void BorrowCommand::read(istream &is) {
  is >> this->customerID;
  is >> this->mediaType;
  is >> this->movieType;
  string str = readNextItem(is);
  this->key = ItemKey(str);
}

// process borrow command
void BorrowCommand::process() {
  Customer *currCustomer =
      CustomerContainer::getInstance().retrieve(this->customerID);
  // check if the customerID is valid, if not print ERROR
  if (currCustomer == nullptr) {
    cerr << "ERROR: invalid customer ID" << endl;
    return;
  }
  // check if the media type is valid, if not print ERROR
  if (this->mediaType != 'D') {
    cerr << "ERROR: invalid media type" << endl;
    return;
  }
  // check if the movie type is valid, if not print ERROR
  if (movieTypes.count(movieType) == 0) {
    cerr << "ERROR: not valid movie type" << endl;
    return;
  }
  // find this item by itemKey, if invalid key print ERROR
  Movie *currMovie =
      Inventory::getInstance().retrieve(this->movieType, this->key);
  if (currMovie == nullptr) {
    cerr << "ERROR: invalid movie" << endl;
    return;
  }
  // check if item is in stock, if not print ERROR
  if (!currMovie->haveInStock()) {
    cerr << "ERROR: do not have this movie in stock" << endl;
    return;
  }
  // decrese the stock and add history to customerHistory
  currMovie->decreaseStock();
  // conver char to string
  string cT(1, this->commandType), mediaT(1, this->mediaType),
      movieT(1, this->movieType);
  string history =
      cT + " " + mediaT + " " + movieT + " " + this->key.getItemKey();
  currCustomer->insertHistory(history);
}

// creating the object registers the type at runtime
BorrowCommandFactory anonymousBorrowCommandFactory;
