/**
 * InventoryCommand.h
 * InventoryCommand is a child of Command class.
 * Inventory (denoted as ‘I’): outputs the inventory of all the items in the
 * store
 *
 * @author Olga Kuriatnyk
 */

#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "command.h"
#include "inventory.h"

using namespace std;

class InventoryCommand : public Command {
public:
  // explicit constructor
  explicit InventoryCommand(const char &commandType);

  // destructor
  ~InventoryCommand() override;

  // copy constructor not allowed
  InventoryCommand(const InventoryCommand &c) = delete;

  // move not allowed
  InventoryCommand(InventoryCommand &&other) = delete;

  // assignment not allowed
  InventoryCommand &operator=(const InventoryCommand &other) = delete;

  // move assignment not allowed
  InventoryCommand &operator=(InventoryCommand &&other) = delete;

  // function for reading inventory commands
  void read(istream &is) override;

  // process inventory command
  void process() override;

private:
};

class InventoryCommandFactory : public CommandFactory {
public:
  // register the Inventory Command factory
  InventoryCommandFactory() { Command::registerType('I', this); }

  // create new Inventory command
  Command *create(const char &commandType) const override {
    return new InventoryCommand(commandType);
  }
};

#endif