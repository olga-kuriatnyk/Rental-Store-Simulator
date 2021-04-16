/**
 * Comedy.cpp
 *  Child class of Movies, a Comedy is a specific type of Movie
 *	Comedy (‘F’) sorted by Title, then Year it released
 *
 * @author Olga Kuriatnyk
 */

#include "comedy.h"

// Constructor
Comedy::Comedy(const char &movieType) { this->movieType = movieType; }

// default destructor
Comedy::~Comedy() = default;

// reads the line from the file and sets the values to this object
// has validation check for stock and year
bool Comedy::read(istream &is) {
  char discardComma;
  is >> this->stock;
  is >> discardComma;
  this->director = readNextItem(is);
  this->title = readNextItem(is);
  is >> this->year;
  if (!isStockValid()) {
    cerr << "ERROR: invalid stock" << endl;
    return false;
  }
  if (!isYearValid()) {
    cerr << "ERROR: invalid year" << endl;
    return false;
  }
  this->title += ",";
  this->mediaType = 'D'; // because right now we only have one media type
  this->itemKey = ItemKey(this->title, to_string(this->year));
  return true;
}

// print our comedy movie object
void Comedy::printMovie() const {
  cout << "GENRE: " << this->getMovieType() << ", TITLE: " << this->title;
  cout << "\n\tDirector: " << this->director
       << ", Year released: " << this->year;
  cout << ", In-stock: " << this->stock << ", Borrowed: " << this->borrowedNum
       << endl;
}

// creating the object registers the type at run time
ComedyFactory anonymousComedyFactory;