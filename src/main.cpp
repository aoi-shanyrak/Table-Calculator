#include <iostream>

#include "parser.hpp"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    Token_stream ts {std::cin};
    Parser parser(ts);

    std::cout << "Table Calculator: Ctrl + D to exit" << std::endl;
    parser.calculate();
  }
  return 0;
}
