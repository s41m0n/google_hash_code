#ifndef GOOGLE_HASH_CODE_GENETICALGORITHM_H
#define GOOGLE_HASH_CODE_GENETICALGORITHM_H

#include <string>
#include <fstream>
#include <mutex>
#include "Database.h"

class GeneticAlgorithm {

public:
    void computeSoreOfAllLibraries(std::vector<Library> &libraries);
    std::vector<Library> sortLibrariesBySignUp(std::vector<Library> &libraries);
    float computeMediumScoreForLibraries(std::vector<Library> &libraries);

};

#endif // GOOGLE_HASH_CODE_GENETICALGORITHM_H
