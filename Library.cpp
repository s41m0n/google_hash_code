//
// Created by s41m0n on 2/20/20.
//

#include "Library.h"
#include <algorithm>
#include <iostream>
#include <utility>

Library::Library(int id, int signupProcessDays, int shippableBooksPerDay)
    : id(id), nBooks(0), mediumScore(0), signupProcessDays(signupProcessDays),
      shippableBooksPerDay(shippableBooksPerDay) {}

void Library::addBook(Book &book) {
  this->books.emplace_back(book);
  this->nBooks++;
}
int Library::getNBooks() { return this->nBooks; }

void Library::computeMediumScoreForBook() {
  int scoreTot = 0;
  for (auto &book : this->books) {
    scoreTot += book.getScore();
  }
  float medScore = scoreTot / this->books.size();
  this->mediumScore = medScore;
}

float Library::getMediumScore() { return this->mediumScore; }

void Library::computeScore() {
  int scoreTot = 0;
  for (auto &book : this->books) {
    scoreTot += book.getScore();
  }
  this->score = scoreTot;
}
int Library::getId() { return this->id; }
int Library::getScore() { return this->score; }
int Library::getSignupProcessDays() { return this->signupProcessDays; }
std::vector<Book> &Library::getBooks() { return this->books; }
int Library::getShippableBooksPerDay() { return this->shippableBooksPerDay; }
void Library::removeBook(int id) {
  int index = 0;
  for (auto &b : this->books) {
    if (b.getId() == id)
      break;
    id++;
  }
  this->books.erase(this->books.begin(), this->books.begin() + index);
}
