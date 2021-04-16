/**
 * Command.h
 * Base class Command, Parent of BorrowCommand, ReturnCommand, HistoreCommand?
 * and InventoryCommand
 *
 * @author Olga Kuriatnyk
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

class Command;

class CommandFactory {
public:
  // virtual create() function will be overridden for
  // drama, comedy, and classic objects separately
  virtual Command *create(const char &commandType) const = 0;
};

class Command {

public:
  // constructor
  Command() = default;
  // destructor
  virtual ~Command() = default;

  // copy constructor not allowed
  Command(const Command &c) = delete;

  // move not allowed
  Command(Command &&other) = delete;

  // assignment not allowed
  Command &operator=(const Command &other) = delete;

  // move assignment not allowed
  Command &operator=(Command &&other) = delete;

  // register the commad factory
  static void registerType(const char &type, CommandFactory *newFactroy);

  // create if there is the command factory
  //@return Commad pointer
  static Command *create(const char &type);

  // virtual function for read command string.
  virtual void read(istream &is) = 0;

  // process command
  virtual void process() = 0;

protected:
  char commandType = ' ';

  set<char> movieTypes{ 'C', 'D', 'F' };

  // helper function for read(istream& is) function
  string readNextItem(istream &io, char end = '\n');

private:
  //@return command factory map
  static map<char, CommandFactory *> &getMap() {
    static map<char, CommandFactory *> factory;
    return factory;
  }
};

#endif