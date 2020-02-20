//
// Created by s41m0n on 2/20/20.
//

#include "Database.h"
#include <iostream>
Database::Database() : libraries(), books() {}

std::string Database::toString() {
  std::string tmp;
  tmp += "Database{"
         "\nnBooks: " +
         std::to_string(this->nBooks) +
         "\nnLibraries: " + std::to_string(this->nLibraries) +
         "\nnDays: " + std::to_string(this->nDays) + "\nBooks: ";
  for (auto &v : this->books) {
    tmp += "{" + std::to_string(v.getId()) + "," +
           std::to_string(v.getScore()) + "} ";
  }
  tmp += "\nLibraries: ";
  for (auto &v : this->libraries) {
    tmp += "{" + std::to_string(v.getId()) + "," +
           std::to_string(v.getNBooks()) + "} ";
  }
  tmp += "\n}";
  return tmp;
}
std::vector<Library> &Database::getLibraries() { return this->libraries; }
std::vector<Book> &Database::getBooks() { return this->books; }
int Database::getNbooks() { return this->nBooks; }
int Database::getNDays() { return this->nDays; }
int Database::getNLibraries() { return this->nLibraries; }
void Database::setNBooks(int nBooks) { this->nBooks = nBooks; }
void Database::setNLibrary(int nLibraries) { this->nLibraries = nLibraries; }
void Database::setNDays(int nDays) { this->nDays = nDays; }
void Database::addBook(Book &book) {
  this->books.emplace_back(book);
}
void Database::addLibrary(Library &library) {
  this->libraries.emplace_back(library);
}
void Database::removeLibrary(int id) {
  this->libraries.erase(this->libraries.begin(), this->libraries.begin() + id);
}
