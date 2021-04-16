/**
 * Command.cpp
 * Base class Command, Parent of BorrowCommand, ReturnCommand, HistoreCommand?
 * and InventoryCommand
 *
 * @author Olga Kuriatnyk
 */

#include "command.h"

// register the commad factory
void Command::registerType(const char &type, CommandFactory *newFactroy) {
  getMap().emplace(type, newFactroy);
}

// create if there is the command factory
//@return Commad pointer
Command *Command::create(const char &type) {
  if (getMap().count(type) == 0) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->create(type);
}

// helper function for read(istream& is) function
string Command::readNextItem(istream &io, char end) {
  const char space = ' ';
  string str;
  getline(io, str, end);
  if (str.empty()) {
    return str;
  }
  return str.substr(str.find_first_not_of(space),
                    str.find_last_not_of(space) + 1);
}