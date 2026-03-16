#pragma once

#include "error.hpp"
#include "lexer.hpp"
#include "parser.hpp"

using Error::error;
using namespace Lexer;

namespace Parser {

  double expr(bool);
  double term(bool);
  double prim(bool);

}
