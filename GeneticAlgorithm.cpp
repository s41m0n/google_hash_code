//
// Created by s41m0n on 2/20/20.
//

#include <algorithm>
#include <utility>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::computeSoreOfAllLibraries(std::vector<Library> &libraries) {
  for (auto & library : libraries){
      library.computeMediumScoreForBook();
  }
}

std::vector<Library> GeneticAlgorithm::sortLibrariesBySignUp(std::vector<Library> &libraries){
  auto libraries_copy = libraries;
  std::sort(libraries_copy.begin(), libraries_copy.end());
  return libraries_copy;
}

float GeneticAlgorithm::computeMediumScoreForLibraries(std::vector<Library> &libraries){
    int sum_of_scores = 0;
    for (auto & library : libraries){
        sum_of_scores += library.getMediumScore();
    }
    return (float)sum_of_scores /
}