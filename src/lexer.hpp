#pragma once
#include <iostream>

enum class Kind : char {
  name,
  number,
  end,
  plus = '+',
  minus = '-',
  mul = '*',
  div = '/',
  print = ';',
  assign = '=',
  lp = '(',
  rp = ')'
};

struct Token {
  Kind kind;
  std::string string_value;
  double number_value;

  Token(Kind k = Kind::end, std::string s = "", double n = 0.0)
      : kind {k}, string_value(std::move(s)), number_value {n} {}
};

class Token_stream {
 public:
  explicit Token_stream(std::istream& s) : ip(&s), owns {false} {}
  explicit Token_stream(std::istream* p) : ip(p), owns {true} {}
  ~Token_stream() { close(); }

  Token get();
  const Token& current();

 private:
  void close() {
    if (owns) delete ip;
  }

  std::istream* ip;
  bool owns;
  Token ct;
};

void error(const std::string&);
