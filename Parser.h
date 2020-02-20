//
// Created by s41m0n on 2/20/20.
//

#ifndef GOOGLE_HASH_CODE_PARSER_H
#define GOOGLE_HASH_CODE_PARSER_H

#include <regex>
#include <string>
#include "Database.h"

class Parser {
public:
  Parser();
  void parse(std::string &filename, Database &db);

private:
  std::string line;
  std::stringstream ss;
};

#endif // GOOGLE_HASH_CODE_PARSER_H
