#include <fstream>
#include <iostream>
#include <regex>

#include "Book.h"
#include "Library.h"
#include "Parser.h"

Parser::Parser() : myRegex(), line() { this->myRegex = "(\\d+)"; }

void Parser::parse(std::string &filename, Database &db) {

  std::ifstream file(filename);
  std::smatch sm;
  if (file.is_open()) {

    // Reading 1st line (main parameters)
    getline(file, line);
    std::regex_search(line, sm, myRegex);
    db.setNBooks(std::stoi(sm.str(1)));
    std::regex_search(line, sm, myRegex);
    db.setNLibrary(std::stoi(sm.str(2)));
    std::regex_search(line, sm, myRegex);
    db.setNDays(std::stoi(sm.str(3)));

    exit(0);
    // Reading 2nd line (Books & score)
    getline(file, line);
    std::regex_search(line, sm, myRegex);
    for (int i = 1; i <= db.getNbooks(); i++) {
      Book book(i - 1, std::stoi(sm.str(i)));
      db.addBook(book);
    }

    // Reading libraries
    for (int i = 1; i <= db.getNLibraries() * 2; i++) {
      getline(file, line);
      std::regex_search(line, sm, myRegex);
      Library library(std::stoi(sm.str(1)), std::stoi(sm.str(2)),
                      std::stoi(sm.str(3)));
      getline(file, line);
      std::regex_search(line, sm, myRegex);
      for (int j = 1; j <= library.getNBooks(); i++) {
        library.addBook(db.getBooks()[std::stoi(sm.str(j))]);
      }
      db.addLibrary(library);
    }

  } else {
    std::cout << "Problem opening file" << std::endl;
    exit(-1);
  }
}
