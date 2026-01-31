#include <iostream>

#include "parser.hpp"

int main() {
  Token_stream ts {std::cin};
  Parser parser(ts);

  parser.calculate();

  return 0;
}
