/**
 * BorrowCommand.h
 * BorrowCommand is a child of Command class.
 * Borrow (denoted as ‘B’): (stock – 1) for each item borrowed.
 *
 * @author Olga Kuriatnyk
 */

#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "command.h"
#include "customerContainer.h"
#include "inventory.h"
#include "itemKey.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class BorrowCommand : public Command {
public:
  // explicit constructor
  explicit BorrowCommand(const char &commandType);

  // destructor
  ~BorrowCommand() override;

  // copy constructor not allowed
  BorrowCommand(const BorrowCommand &c) = delete;

  // move not allowed
  BorrowCommand(BorrowCommand &&other) = delete;

  // assignment not allowed
  BorrowCommand &operator=(const BorrowCommand &other) = delete;

  // move assignment not allowed
  BorrowCommand &operator=(BorrowCommand &&other) = delete;

  // read the command string load into customerID and key
  void read(istream &is) override;

  // process borrow command
  void process() override;

private:
  int customerID;
  char mediaType, movieType;
  ItemKey key;
};

class BorrowCommandFactory : public CommandFactory {
public:
  // register the Borrow Command factory
  BorrowCommandFactory() { Command::registerType('B', this); }

  // create new borrow command
  Command *create(const char &commandType) const override {
    return new BorrowCommand(commandType);
  }
};

#endif