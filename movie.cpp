/**
 * Movie.cpp
 * Base class Movies, Parent of Classics, Comedy and Drama
 *
 * @author Olga Kuriatnyk
 */

#include "movie.h"

// constructor
Movie::Movie() {
  this->director = "";
  this->title = "";
  this->year = 0;
  this->stock = 0;
  this->borrowedNum = 0;
  this->mediaType = ' ';
  this->movieType = ' ';
}

// register movie type
void Movie::registerType(const char &movieType, MovieFactory *factory) {
  getMap().emplace(movieType, factory);
}

// create movie of this type
Movie *Movie::create(const char &movieType) {
  if (getMap().count(movieType) == 0) {
    cout << "Don't know how to create " << movieType << endl;
    return nullptr;
  }
  return getMap().at(movieType)->create(movieType);
}

// @return char for the movie type
char Movie::getMovieType() const { return this->movieType; }

// @return ItemKey of the object
ItemKey Movie::getItemKey() const { return this->itemKey; }

// @return true if year is valid from 1800 to current year
bool Movie::isYearValid() const {
  time_t theTime = time(nullptr);
  struct tm *aTime = localtime(&theTime);
  int currYear = aTime->tm_year + 1900;
  return (year > 1800 && year < currYear);
}

// decrease stock for borrow command
void Movie::decreaseStock() {
  this->stock -= 1;
  this->borrowedNum += 1;
}

// increase stock for return command
void Movie::increaseStock() {
  this->stock += 1;
  this->borrowedNum -= 1;
}

// @return true if have 1 or more
// use for borrow command
bool Movie::haveInStock() const { return this->stock > 0; }

// @return true if stack is 0 or more
bool Movie::isStockValid() const { return this->stock >= 0; }

// helper function for read(istream& is) function
string Movie::readNextItem(istream &io, char comma) {
  const char space = ' ';
  string str;
  getline(io, str, comma);
  if (str.empty()) {
    return str;
  }
  return str.substr(str.find_first_not_of(space),
                    str.find_last_not_of(space) + 1);
}