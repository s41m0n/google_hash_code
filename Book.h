//
// Created by s41m0n on 2/20/20.
//

#ifndef GOOGLE_HASH_CODE_BOOK_H
#define GOOGLE_HASH_CODE_BOOK_H

#include <string>

class Book {
private:
  int id;
  int score;
public:
  Book(int id, int score);
  int getScore();
  int getId();
  bool operator<(const Book &other) const {
    return score < other.score;
  }
};

#endif // GOOGLE_HASH_CODE_BOOK_H
