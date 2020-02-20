//
// Created by s41m0n on 2/20/20.
//

#ifndef GOOGLE_HASH_CODE_LIBRARY_H
#define GOOGLE_HASH_CODE_LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"

class Library {

private:
  int id;
  int nBooks;
  int signupProcessDays;
  int shippableBooksPerDay;
  float mediumScore;
  std::vector<Book> books;

public:
  Library(int id, int signupProcessDays, int shippableBooksPerDay);
  void addBook(Book &book);
  int getNBooks();
  float getMediumScore();
  void computeScore();
};

#endif // GOOGLE_HASH_CODE_LIBRARY_H
