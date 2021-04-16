/**
 * HistoryCommand.h
 * HistoryCommand is a child of Command class.
 * History (denoted as ‘H’): outputs all the transactions of a customer
 *
 * @author Olga Kuriatnyk
 */

#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"
#include "customerContainer.h"

using namespace std;

class HistoryCommand : public Command {
public:
  // explicit constructor
  explicit HistoryCommand(const char &commandType);

  // destructor
  ~HistoryCommand() override;

  // copy constructor not allowed
  HistoryCommand(const HistoryCommand &c) = delete;

  // move not allowed
  HistoryCommand(HistoryCommand &&other) = delete;

  // assignment not allowed
  HistoryCommand &operator=(const HistoryCommand &other) = delete;

  // move assignment not allowed
  HistoryCommand &operator=(HistoryCommand &&other) = delete;

  // function for reading history commands
  void read(istream &is) override;

  // process history command
  void process() override;

private:
  int customerID;
};
class HistoryCommandFactory : public CommandFactory {
public:
  // register the History Command factory
  HistoryCommandFactory() { Command::registerType('H', this); }

  // create new history command
  Command *create(const char &commandType) const override {
    return new HistoryCommand(commandType);
  }
};

#endif