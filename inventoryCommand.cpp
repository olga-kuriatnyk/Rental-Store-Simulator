/**
 * InventoryCommand.cpp
 * InventoryCommand is a child of Command class.
 * Inventory (denoted as ‘I’): outputs the inventory of all the items in the
 * store
 *
 * @author Olga Kuriatnyk
 */

#include "inventoryCommand.h"

// explicit constructor
InventoryCommand::InventoryCommand(const char &commandType) {
  this->commandType = commandType;
}

// default destructor
InventoryCommand::~InventoryCommand() = default;

// function for reading inventory commands
// we don't need to read anything here because the command is one char
void InventoryCommand::read(istream &is) {
  string s;
  is >> s;
}

// process inventory command
void InventoryCommand::process() { Inventory::getInstance().printInventory(); }

// creating the object registers the type at run time
InventoryCommandFactory anonymousInventoryCommandFactory;