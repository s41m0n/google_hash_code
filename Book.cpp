//
// Created by s41m0n on 2/20/20.
//

#include "Book.h"
Book::Book(int id, int score) : id(id), score(score){}

int Book::getScore(){
  return this->score;
}
int Book::getId() { return this->id; }
