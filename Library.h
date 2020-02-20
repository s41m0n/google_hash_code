//
// Created by s41m0n on 2/20/20.
//

#ifndef GOOGLE_HASH_CODE_LIBRARY_H
#define GOOGLE_HASH_CODE_LIBRARY_H

#include "Book.h"
#include <string>
#include <vector>

class Library {

private:
  int id;
  int nBooks;
  int signupProcessDays;
  int shippableBooksPerDay;
  int score;
  float mediumScore;
  std::vector<Book> books;

public:
  Library()
      : id(-1), nBooks(-1), signupProcessDays(-1), shippableBooksPerDay(-1),
        mediumScore(-1), score(-1){};
  Library(int id, int signupProcessDays, int shippableBooksPerDay);
  void addBook(Book &book);
  int getNBooks();
  float getMediumScore();
  std::vector<Book> &getBooks();
  void computeMediumScoreForBook();
  void computeScore();
  void removeBook(int id);
  int getScore();
  int getShippableBooksPerDay();
  int getSignupProcessDays();
  bool operator<(const Library &other) const {
    return signupProcessDays < other.signupProcessDays;
  }
  int getId();
};

#endif // GOOGLE_HASH_CODE_LIBRARY_H
