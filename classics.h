/**
 * Classic.h
 *  Child class of Movies, a Classics is a specific type of Movie
 *	that unlike all movies a Classics movie has Major Actor and Release Date
 *  Classics (‘C’) are sorted by Release date, then Major actor
 *
 * @authorOlga Kuriatnyk
 */

#ifndef CLASSIC_H
#define CLASSIC_H

#include <ostream>

#include "movie.h"

class Classics : public Movie {
public:
  // Constructor
  explicit Classics(const char &movieType);

  // Default destructor
  ~Classics() override;

  // copy constructor not allowed
  Classics(const Classics &c) = delete;

  // move not allowed
  Classics(Classics &&other) = delete;

  // assignment not allowed
  Classics &operator=(const Classics &other) = delete;

  // move assignment not allowed
  Classics &operator=(Classics &&other) = delete;

  // reads the line from the file and sets the values to this object
  // has validation check for stock, year and month
  bool read(istream &is) override;

  // overload for printing out movie
  void printMovie() const override;

private:
  string majorActor;
  string releaseDate;

  // @return true if the month is from 1 to 12
  bool isMonthValid(const int &month) const;
};

// Creating ClassicFactory to make Classic objects
// ClassicFactory object will register itself later and get stored in the Item
// class
class ClassicsFactory : public MovieFactory {
public:
  // when called will register Classic in the Item class
  ClassicsFactory() { Movie::registerType('C', this); }

  // @return new Item object
  Movie *create(const char &movieType) const override {
    return new Classics(movieType);
  };
};

#endif