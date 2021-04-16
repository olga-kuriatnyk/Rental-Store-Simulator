/**
 * Comedy.h
 *  Drama class of Movies, a Drama is a specific type of Movie
 *  Dramas (‘D’) are sorted by Director, then Title
 *
 * @author Olga Kuriatnyk
 */

#include "drama.h"

// explicit constructor
Drama::Drama(const char &movieType) { this->movieType = movieType; }

// Default destructor
Drama::~Drama() = default;

// reads the line from the file and sets the values to this object
// has validation check for stock and year
bool Drama::read(istream &is) {
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
  this->director += ",";
  this->title += ",";
  this->mediaType = 'D'; // because right now we only have one media type
  this->itemKey = ItemKey(this->director, this->title); // set ItemKey
  return true;
}

// print our drama movie object
void Drama::printMovie() const {
  cout << "GENRE: " << this->getMovieType() << ", TITLE: " << this->title;
  cout << "\n\tDirector: " << this->director
       << " Year released: " << this->year;
  cout << ", In-stock: " << this->stock << ", Borrowed: " << this->borrowedNum
       << endl;
}

// creating the object registers the type at run time
DramaFactory anonymousDramaFactory;