/**
 * Testing ass4 movie store functions
 *
 * @author Olga Kuriatnyk
 * @date 3/16/2021
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "store.h"

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  string customersFile = "customers.txt";
  string moviesFile = "movies.txt";
  string commandsFile = "commands.txt";
  Store store;
  store.readCustomersFromFile(customersFile);
  store.readMoviesFromFile(moviesFile);
  store.readCommandsFromFile(commandsFile);
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  string customersFile = "data4customers.txt";
  string moviesFile = "data4movies.txt";
  string commandsFile = "data4commands.txt";
  Store store;
  store.readCustomersFromFile(customersFile);
  store.readMoviesFromFile(moviesFile);
  store.readCommandsFromFile(commandsFile);
  store.processCommands();
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
