/**
 * Classic.cpp
 *  Child class of Movies, a Classics is a specific type of Movie
 *	that unlike all movies a Classics movie has Major Actor and Release Date
 *  Classics (‘C’) are sorted by Release date, then Major actor
 *
 * @author Olga Kuriatnyk
 */

#include "classics.h"

// Constructor
Classics::Classics(const char &movieType) { this->movieType = movieType; }

// default destructor
Classics::~Classics() = default;

// reads the line from the file and sets the values to this object
// has validation check for stock, year and month
bool Classics::read(istream &is) {
  string majorActorFirstName, majorActorLastName;
  int month;
  char discardComma;
  is >> this->stock >> discardComma;
  this->director = readNextItem(is);
  this->title = readNextItem(is);
  is >> majorActorFirstName >> majorActorLastName;
  is >> month >> this->year;
  if (!isStockValid()) {
    cerr << "ERROR: invalid stock" << endl;
    return false;
  }
  if (!isYearValid() || !isMonthValid(month)) {
    cerr << "ERROR: invalid date" << endl;
    return false;
  }
  this->mediaType = 'D'; // because right now we only have one media type
  this->majorActor = majorActorFirstName + " " + majorActorLastName;
  this->releaseDate = to_string(month) + " " + to_string(this->year);
  this->itemKey = ItemKey(this->releaseDate, this->majorActor);
  return true;
}

// overload for printing out movie
void Classics::printMovie() const {
  cout << "GENRE: " << this->getMovieType() << ", TITLE: " << this->title;
  cout << "\n\tDirector: " << this->director
       << ", Major Actor: " << this->majorActor;
  cout << ", Year released: " << this->year;
  cout << ", In-stock: " << this->stock << ", Borrowed: " << this->borrowedNum
       << endl;
}

// @return true if the month is from 1 to 12
bool Classics::isMonthValid(const int &month) const {
  return (month >= 1 && month <= 12);
}

// creating the object registers the type at run time
ClassicsFactory anonymousClassicsFactory;
