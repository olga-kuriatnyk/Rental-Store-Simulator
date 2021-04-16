/**
 * Store.h
 *  Store class read files for movies, customers, and commands.
 *  This class stores the list of commands and process them.
 *
 * @author Olga Kuriatnyk
 */

#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "command.h"
#include "customer.h"
#include "customerContainer.h"
#include "inventory.h"
#include "movie.h"

using namespace std;

class Store {
public:
  // defaulf constructor
  Store() = default;

  // destructor
  ~Store();

  // copy constructor not allowed
  Store(const Store &c) = delete;

  // move not allowed
  Store(Store &&other) = delete;

  // assignment not allowed
  Store &operator=(const Store &other) = delete;

  // move assignment not allowed
  Store &operator=(Store &&other) = delete;

  // reading list of customers from the file
  void readCustomersFromFile(const string &filename);

  // read list of movies from the file
  void readMoviesFromFile(const string &filename);

  // reading commands from the file
  void readCommandsFromFile(const string &filename);

  // processing all comands
  void processCommands();

private:
  // data structure for all commands
  vector<Command *> commands;
};
#endif
