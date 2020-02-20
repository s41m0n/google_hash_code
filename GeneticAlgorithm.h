#ifndef GOOGLE_HASH_CODE_GENETICALGORITHM_H
#define GOOGLE_HASH_CODE_GENETICALGORITHM_H

#include <string>
#include <fstream>
#include <mutex>
#include "Database.h"
#include "Database.h"

class GeneticAlgorithm {

private:
  float GLOBAL_MEAN = 0.5;
  void computeScoreOfAllLibraries(Database &db);
  void sortLibrariesBySignUp(Database &db);
  float computeMediumScoreForLibraries(Database &db);
  Library findCandidateLibrary(Database &db);

public:
  GeneticAlgorithm();
  void start(Database &db);

};

#endif // GOOGLE_HASH_CODE_GENETICALGORITHM_H
