/**
 * ReturnCommand.cpp
 * ReturnCommand is a child of Command class.
 * Return (denoted as ‘R’): (stock + 1) for each item returned
 *
 * @author Olga Kuriatnyk
 */

#include "returnCommand.h"

// constructor
ReturnCommand::ReturnCommand(const char &commandType) {
  this->commandType = commandType;
  this->customerID = 0;
  this->mediaType = ' ';
  this->movieType = ' ';
}

// default destructor
ReturnCommand::~ReturnCommand() = default;

// read the command string load into customerID and key
void ReturnCommand::read(istream &is) {
  is >> this->customerID;
  is >> this->mediaType;
  is >> this->movieType;
  string str = readNextItem(is);
  this->key = ItemKey(str);
}

// process return command
void ReturnCommand::process() {
  Customer *customerTemp =
      CustomerContainer::getInstance().retrieve(this->customerID);
  // check if the customerID is valid, if not print ERROR
  if (customerTemp == nullptr) {
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
  // find this item by itemKey
  Movie *movieTemp =
      Inventory::getInstance().retrieve(this->movieType, this->key);
  if (movieTemp == nullptr) {
    cerr << "ERROR: invalid movie" << endl;
    return;
  }
  // conver char to string
  string cT(1, this->commandType), mediaT(1, this->mediaType),
      movieT(1, this->movieType);
  string history =
      cT + " " + mediaT + " " + movieT + " " + this->key.getItemKey();
  if (customerTemp->findHistory("B " + mediaT + " " + movieT + " " +
                                this->key.getItemKey())) {
    string history =
        cT + " " + mediaT + " " + movieT + " " + this->key.getItemKey();
    movieTemp->increaseStock();
    customerTemp->insertHistory(history);
  } else {
    cerr << "ERROR: this movie was not borrowed" << endl;
  }
}

// creating the object registers the type at run time
ReturnCommandFactory anonymousReturnCommandFactory;
