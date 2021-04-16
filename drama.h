/**
 * Comedy.h
 *  Drama class of Movies, a Drama is a specific type of Movie
 *  Dramas (‘D’) are sorted by Director, then Title
 *
 * @author Olga Kuriatnyk
 */

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  // explicit constructor
  explicit Drama(const char &movieType);

  // destructor
  ~Drama() override;

  // copy constructor not allowed
  Drama(const Drama &c) = delete;

  // move not allowed
  Drama(Drama &&other) = delete;

  // assignment not allowed
  Drama &operator=(const Drama &other) = delete;

  // move assignment not allowed
  Drama &operator=(Drama &&other) = delete;

  // reads the line from the file and sets the values to this object
  // has validation check for stock and year
  bool read(istream &is) override;

  // print our drama movie object
  void printMovie() const override;
};

// Creating DramaFactory to make Drama objects
// DramaFactory object will register itself later and get stored in the Item
// class
class DramaFactory : public MovieFactory {
public:
  // when called will register Drama in the Item class
  DramaFactory() { Movie::registerType('D', this); }

  // @return new drama object
  Movie *create(const char &movieType) const override {
    return new Drama(movieType);
  }
};
#endif