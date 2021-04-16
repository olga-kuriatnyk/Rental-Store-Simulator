/**
 * Movie.h
 * Base class Movies, Parent of Classics, Comedy and Drama
 *
 * @author Olga Kuriatnyk
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "itemKey.h"
#include <ctime>

using namespace std;

// declaration of a class movie
class Movie;

class MovieFactory {
public:
  // virtual create() function will be overridden for
  // drama, comedy, and classic objects separately
  virtual Movie *create(const char &movieType) const = 0;
};

class Movie {
public:
  // constructor
  Movie();

  // destructor
  virtual ~Movie() = default;

  // copy constructor not allowed
  Movie(const Movie &c) = delete;

  // move not allowed
  Movie(Movie &&other) = delete;

  // assignment not allowed
  Movie &operator=(const Movie &other) = delete;

  // move assignment not allowed
  Movie &operator=(Movie &&other) = delete;

  // register movie type
  static void registerType(const char &movieType, MovieFactory *factory);

  // create movie of this type
  static Movie *create(const char &movieType);

  // @return char for the movie type
  char getMovieType() const;

  // @return ItemKey of the object
  ItemKey getItemKey() const;

  // virtual function to read the line from the file and sets the values to this
  // object
  virtual bool read(istream &is) = 0;

  // @return true if year is valid from 1800 to current year
  bool isYearValid() const;

  // For Borrow/Return commands
  // decrease stock for borrow command
  void decreaseStock();

  // increase stock for return command
  void increaseStock();

  // @return true if have 1 or more
  // use for borrow command
  bool haveInStock() const;

  // virtual function to print out movie object
  // should be overridden for drama, comedy, and classic objects separately
  virtual void printMovie() const = 0;

  // protected variables for child classes
protected:
  ItemKey itemKey;
  string director, title;
  int year, stock, borrowedNum;
  char movieType, mediaType;

  // @return true if stack is 0 or more
  bool isStockValid() const;

  // helper function for read(istream& is) function
  string readNextItem(istream &io, char comma = ',');

private:
  // Storage place for the concrete movie factory
  // Having it available only through this function guarantees that
  // this static variable is initialized
  // when a concrete factory tires to register itself
  // @return map
  static map<char, MovieFactory *> &getMap() {
    static map<char, MovieFactory *> factories;
    return factories;
  }
};
#endif