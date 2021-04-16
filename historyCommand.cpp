/**
 * HistoryCommand.cpp
 * HistoryCommand is a child of Command class.
 * History (denoted as ‘H’): outputs all the transactions of a customer
 *
 * @author Olga Kuriatnyk
 */

#include "historyCommand.h"

// explicit constructor
HistoryCommand::HistoryCommand(const char &commandType) {
  this->commandType = commandType;
  this->customerID = 0;
}

// default destructor
HistoryCommand::~HistoryCommand() = default;

// function for reading history commands
void HistoryCommand::read(istream &is) { is >> this->customerID; }

// process history command
void HistoryCommand::process() {
  Customer *customerTemp =
      CustomerContainer::getInstance().retrieve(this->customerID);
  // check if the customerID is valid, if not print ERROR
  if (customerTemp == nullptr) {
    cerr << "ERROR: invalid customer ID" << endl;
    return;
  }
  customerTemp->printCustomerHistory();
}

// creating the object registers the type at run time
HistoryCommandFactory anonymousHistoryCommandFactory;
