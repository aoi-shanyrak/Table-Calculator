#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"
#include "table.hpp"

namespace Driver {

  void calculate() {
    bool need_arrow = true;
    while (true) {
      if (need_arrow) {
        std::cout << "> ";
        need_arrow = false;
      }
      Lexer::ts.get();
      if (Lexer::ts.current().kind == Lexer::Kind::end) break;
      if (Lexer::ts.current().kind == Lexer::Kind::print) {
        need_arrow = true;
        continue;
      }
      std::cout << Parser::expr(false) << std::endl;
      need_arrow = true;
    }
  }

}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Table Calculator: Ctrl + D to exit" << std::endl;
    Driver::calculate();
  }
  return 0;
}
