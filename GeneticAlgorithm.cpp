//
// Created by s41m0n on 2/20/20.
//

#include "GeneticAlgorithm.h"
#include <algorithm>
#include <iostream>
#include <map>

GeneticAlgorithm::GeneticAlgorithm() {}

void GeneticAlgorithm::computeScoreOfAllLibraries(Database &db) {
  for (auto &library : db.getLibraries()) {
    library.computeMediumScoreForBook();
    library.computeScore();
  }
}

void GeneticAlgorithm::sortLibrariesBySignUp(Database &db) {
  std::sort(db.getLibraries().begin(), db.getLibraries().end());
}

float GeneticAlgorithm::computeMediumScoreForLibraries(Database &db) {
  int sum_of_scores = 0;
  for (auto &library : db.getLibraries()) {
    sum_of_scores += library.getScore();
  }
  return sum_of_scores / db.getNLibraries();
}

Library GeneticAlgorithm::findCandidateLibrary(Database &db) {
  this->computeScoreOfAllLibraries(db);
  this->sortLibrariesBySignUp(db);
  float mean = this->computeMediumScoreForLibraries(db);
  Library chosen;

  for (auto &v : db.getLibraries()) {
    if (v.getScore() >= this->GLOBAL_MEAN * mean) {
      // check is valid
      if (chosen.getId() < 0 || v.getScore() > chosen.getScore()) {
        chosen = v;
      }
    }
  }
  return chosen;
}

void GeneticAlgorithm::start(Database &db) {
  std::vector<Book> alreadyScannedBooks;
  std::vector<Library> usedLibraries;

  Library chosen = findCandidateLibrary(db);
  usedLibraries.emplace_back(chosen);
  db.removeLibrary(chosen.getId());

  int chosenLibrarySignupDays = chosen.getSignupProcessDays();
  std::map<int, std::vector<Book>> readyForScanning;
  std::vector<Library> currentLibraries;

  for (int days = 0; days < db.getNDays(); days++, chosenLibrarySignupDays--) {
    if (chosenLibrarySignupDays <= 0) {
      std::sort(chosen.getBooks().begin(), chosen.getBooks().end());
      currentLibraries.emplace_back(chosen);

      // NEW SIGNUP
      chosen = findCandidateLibrary(db);
      chosenLibrarySignupDays = chosen.getSignupProcessDays();
      db.removeLibrary(chosen.getId());
      usedLibraries.emplace_back(chosen);
    }

    // SCANNING
    for (auto &lib : currentLibraries) {
      for (int count = 0, i = 0; i < lib.getNBooks(); i++) {
        if (count >= lib.getShippableBooksPerDay()) {
          break;
        }
        if (std::find(alreadyScannedBooks.begin(), alreadyScannedBooks.end(),
                      lib.getBooks()[i]) != alreadyScannedBooks.end()) {
          alreadyScannedBooks.emplace_back(lib.getBooks()[i]);
          count++;
        }
        lib.removeBook(lib.getBooks()[i].getId());
      }
    }
  }
}
