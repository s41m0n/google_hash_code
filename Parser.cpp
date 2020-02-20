#include <fstream>
#include <iostream>
#include <regex>

#include "Book.h"
#include "Library.h"
#include "Parser.h"

Parser::Parser() : line() {}

void Parser::parse(std::string &filename, Database &db) {

  std::ifstream file(filename);
  std::smatch sm;
  if (file.is_open()) {

    // Reading 1st line (main parameters)
    getline(file, line);
    ss = std::stringstream(line);

    std::getline(ss, line, ' ');
    db.setNBooks(std::stoi(line));
    std::getline(ss, line, ' ');
    db.setNLibrary(std::stoi(line));
    std::getline(ss, line, ' ');
    db.setNDays(std::stoi(line));

    // Reading 2nd line (Books & score)
    getline(file, line);
    ss = std::stringstream(line);
    for (int i = 1; i <= db.getNbooks(); i++) {
      std::getline(ss, line, ' ');
      Book book(i - 1, std::stoi(line));
      db.addBook(book);
    }

    // Reading libraries
    for (int i = 1; i <= db.getNLibraries(); i++) {
      getline(file, line);
      ss = std::stringstream(line);
      std::getline(ss, line, ' ');
      int nBooks = std::stoi(line);
      std::getline(ss, line, ' ');
      int signupProcessDays = std::stoi(line);
      std::getline(ss, line, ' ');
      int shippableBooksPerDay = std::stoi(line);

      Library library(i, signupProcessDays, shippableBooksPerDay);
      getline(file, line);
      ss = std::stringstream(line);
      for (int j = 1; j <= nBooks; j++) {
        std::getline(ss, line, ' ');
        library.addBook(db.getBooks()[std::stoi(line)]);
        exit(0);
      }
      db.addLibrary(library);
    }

  } else {
    std::cout << "Problem opening file" << std::endl;
    exit(-1);
  }
}
