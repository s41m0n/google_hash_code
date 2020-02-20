//
// Created by s41m0n on 2/20/20.
//

#ifndef GOOGLE_HASH_CODE_DATABASE_H
#define GOOGLE_HASH_CODE_DATABASE_H

#include <string>
#include <vector>
#include "Library.h"
#include "Book.h"

class Database {
private:
  int nBooks{};
  int nLibraries{};
  int nDays{};
  std::vector<Library> libraries;
  std::vector<Book> books;
public:
  Database();
  std::string toString();
  std::vector<Library> &getLibraries();
  std::vector<Book> &getBooks();
  void setNBooks(int nBooks);
  void setNLibrary(int nLibraries);
  void setNDays(int nDays);
  void addBook(Book &book);
  void addLibrary(Library &library);
  int getNbooks();
  int getNLibraries();
  int getNDays();
  void removeLibrary(int id);

};

#endif // GOOGLE_HASH_CODE_DATABASE_H
