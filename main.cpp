#include <string>
#include <iostream>
#include "Parser.h"
#include "Database.h"
#include "GeneticAlgorithm.h"


int main(int argc, char *argv[]) {
  std::string filename(argv[1]);
  Parser parser;
  Database db;
  GeneticAlgorithm genAlg;

  parser.parse(filename, db);
  std::cout << db.toString() << std::endl;
  genAlg.start(db);

  return 0;
}
