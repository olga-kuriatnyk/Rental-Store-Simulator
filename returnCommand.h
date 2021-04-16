/**
 * ReturnCommand.h
 * ReturnCommand is a child of Command class.
 * Return (denoted as ‘R’): (stock + 1) for each item returned
 *
 * @author Olga Kuriatnyk
 */

#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "command.h"
#include "customerContainer.h"
#include "inventory.h"
#include "itemKey.h"

using namespace std;

// return command is a child class of Command
class ReturnCommand : public Command {
public:
  // constructor
  explicit ReturnCommand(const char &commandType);

  // destructor
  ~ReturnCommand() override;

  // copy constructor not allowed
  ReturnCommand(const ReturnCommand &c) = delete;

  // move not allowed
  ReturnCommand(ReturnCommand &&other) = delete;

  // assignment not allowed
  ReturnCommand &operator=(const ReturnCommand &other) = delete;

  // move assignment not allowed
  ReturnCommand &operator=(ReturnCommand &&other) = delete;

  // read the command string load into customerID and key
  void read(istream &is) override;

  // process return command
  void process() override;

private:
  int customerID;
  char mediaType, movieType;
  ItemKey key;
};

class ReturnCommandFactory : public CommandFactory {
public:
  // register return command Factory
  ReturnCommandFactory() { Command::registerType('R', this); }

  // create new inventory command
  Command *create(const char &commandType) const override {
    return new ReturnCommand(commandType);
  }
};

#endif