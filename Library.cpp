//
// Created by s41m0n on 2/20/20.
//

#include "Library.h"
Library::Library(int id, int signupProcessDays, int shippableBooksPerDay)
    : id(id), nBooks(0), signupProcessDays(signupProcessDays),
      shippableBooksPerDay(shippableBooksPerDay) {}

void Library::addBook(Book &book) {
  this->books.emplace_back(book);
  this->nBooks++;
}
int Library::getNBooks() { return this->nBooks; }
