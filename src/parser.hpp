#pragma once
#include <map>

#include "lexer.hpp"

class Parser {
 public:
  explicit Parser(Token_stream& t) : ts(t) {}

  void calculate();

 private:
  Token_stream& ts;
  std::map<std::string, double> table;

  double expr(bool);
  double term(bool);
  double prim(bool);
};
