/**
 * Comedy.h
 *  Child class of Movies, a Comedy is a specific type of Movie
 *	Comedy (‘F’) sorted by Title, then Year it released
 *
 * @author Olga Kuriatnyk
 */

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
  // explicit constructor
  explicit Comedy(const char &movieType);

  // destructor
  ~Comedy() override;

  // copy constructor not allowed
  Comedy(const Comedy &c) = delete;

  // move not allowed
  Comedy(Comedy &&other) = delete;

  // assignment not allowed
  Comedy &operator=(const Comedy &other) = delete;

  // move assignment not allowed
  Comedy &operator=(Comedy &&other) = delete;

  // reads the line from the file and sets the values to this object
  // has validation check for stock and year
  bool read(istream &is) override;

  // print our comedy movie object
  void printMovie() const override;
};

// Creating ComedyFactory to make Comedy objects
// ComedyFactory object will register itself later and get stored in the Item
// class
class ComedyFactory : public MovieFactory {
public:
  // Constructor?
  // when called will register Comedy in the Item class
  ComedyFactory() { Movie::registerType('F', this); }

  // @return new Item object
  Movie *create(const char &movieType) const override {
    return new Comedy(movieType);
  }
};

#endif
