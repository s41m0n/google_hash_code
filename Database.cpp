//
// Created by s41m0n on 2/20/20.
//

#include "Database.h"
Database::Database() : libraries(), books() {}

std::string Database::toString() { return std::string(); }
std::vector<Library> &Database::getLibraries() { return this->libraries; }
std::vector<Book> &Database::getBooks() { return this->books; }
int Database::getNbooks() { return this->nBooks; }
int Database::getNDays() { return this->nDays; }
int Database::getNLibraries() { return this->nLibraries; }
void Database::setNBooks(int nBooks) { this->nBooks = nBooks; }
void Database::setNLibrary(int nLibraries) { this->nLibraries = nLibraries; }
void Database::setNDays(int nDays) { this->nDays = nDays; }
void Database::addBook(Book &book) { this->books.emplace_back(book); }
void Database::addLibrary(Library &library) {
  this->libraries.emplace_back(library);
}
