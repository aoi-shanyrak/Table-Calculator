#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"

void Parser::calculate() {
  while (true) {
    ts.get();
    if (ts.current().kind == Kind::end) break;
    if (ts.current().kind == Kind::print) continue;
    std::cout << expr(false) << std::endl;
  }
}

double Parser::expr(bool get) {
  double left = term(get);

  while (true) {
    switch (ts.current().kind) {
      case Kind::plus: left += term(true); break;
      case Kind::minus: left -= term(true); break;
      default: return left;
    }
  }
}

double Parser::term(bool get) {
  double left = prim(get);

  while (true) {
    switch (ts.current().kind) {
      case Kind::mul: left *= prim(true); break;
      case Kind::div: left /= prim(true); break;
      default: return left;
    }
  }
}

double Parser::prim(bool get) {
  if (get) ts.get();

  switch (ts.current().kind) {
    case Kind::number: {
      double val = ts.current().number_value;
      ts.get();
      return val;
    }
    case Kind::name: {
      double& val = table[ts.current().string_value];
      if (ts.get().kind == Kind::assign) val = expr(true);
      return val;
    }
    case Kind::minus: return -prim(true);
    case Kind::lp: {
      double e = expr(true);
      if (ts.current().kind != Kind::rp) error("missing ')'");
      ts.get();
      return e;
    }
    default: error("primary expected"); return 0;
  }
}
