//
// Created by s41m0n on 2/20/20.
//

#include "GeneticAlgorithm.h"

void GeneticAlgorithm::computeSoreOfAllLibraries(std::vector<Library> libraries) {
  for (auto & library : libraries){
    library.computeScore();
  }
}

std::vector<Library> GeneticAlgorithm::sortLibrariesBySignUp(std::vector<Library> libraries){
  auto vecLibr = new std::vector<Library>();
  
}
