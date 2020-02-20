#include <string>
#include <iostream>
#include <thread>
#include "Parser.h"
#include "Database.h"
//#include "geneticAlgorithm.h"

/*
void doOnThread(Database *db, int seconds, SharedData *shared, string filename) {
  GeneticAlgorithm *algorithm = new GeneticAlgorithm(db, seconds, filename);
  algorithm->run(shared);
  return;
}
*/

int main(int argc, char *argv[]) {
  std::string filename(argv[1]);
  Parser parser;
  Database db;
  parser.parse(filename, db);
  std::cout << db.toString() << std::endl;
  return 0;
}
