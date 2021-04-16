/**
 * Store.cpp
 *  Store class read files for movies, customers, and commands.
 *  This class stores the list of commands and process them.
 *
 * @author Olga Kuriatnyk
 */

#include "store.h"

// destructor
Store::~Store() {
  auto itr = commands.begin();
  while (!commands.empty()) {
    delete *itr;
    commands.erase(itr);
    itr = commands.begin();
  }
}

// reading list of customers from the file
void Store::readCustomersFromFile(const string &filename) {
  fstream fs;
  fs.open(filename);
  if (!fs.is_open()) {
    cerr << "Could not open file: " << filename << endl;
    return;
  }
  string readInput;
  while (getline(fs, readInput)) {
    if (readInput.empty()) {
      break;
    }
    stringstream lineInput(readInput);
    getline(lineInput, readInput, ' ');
    int id = stoi(readInput);
    bool validID = CustomerContainer::getInstance().validID(id);
    if (validID) {
      Customer *customer = CustomerFactory::create(id);
      customer->read(lineInput);
      CustomerContainer::getInstance().insert(customer);
    } else {
      cerr << "ERROR: invalid customer ID " << readInput << endl;
    }
  }
  fs.close();
}

// read list of movies from the file
void Store::readMoviesFromFile(const string &filename) {
  fstream fs;
  fs.open(filename);
  if (!fs.is_open()) {
    cerr << "Could not open file: " << filename << endl;
    return;
  }
  string readInput;
  while (getline(fs, readInput)) {
    if (readInput.empty()) {
      break;
    }
    stringstream lineInput(readInput);
    // read the character
    getline(lineInput, readInput, ',');
    char type = readInput[0];
    // create a movie using the item factory
    Movie *tempMovie = Movie::create(type);
    if (tempMovie != nullptr) {
      bool validMovie = tempMovie->read(lineInput);
      if (validMovie) {
        tempMovie->printMovie();
        Inventory::getInstance().insert(tempMovie);
      } else {
        delete tempMovie;
      }
    }
  }
  fs.close();
  Inventory::getInstance().sortItems();
}

// reading commands from the file
void Store::readCommandsFromFile(const string &filename) {
  fstream fs;
  fs.open(filename);
  if (!fs.is_open()) {
    cerr << "Could not open file: " << filename << endl;
    return;
  }
  string readInput;
  while (getline(fs, readInput)) {
    if (readInput.empty()) {
      break;
    }
    stringstream lineInput(readInput);
    // read the character
    getline(lineInput, readInput, ' ');
    char type = readInput[0];
    Command *tempCommand = Command::create(type);
    if (tempCommand != nullptr) {
      tempCommand->read(lineInput);
      commands.push_back(tempCommand);
    }
  }
  fs.close();
}

// processing all comands
void Store::processCommands() {
  cout << "\n";
  for (auto &command : commands) {
    command->process();
  }
}
