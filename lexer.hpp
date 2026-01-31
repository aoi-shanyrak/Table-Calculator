#pragma once
#include <iostream>
#include <memory>

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
  Token_stream(std::istream& s) : ip(&s) {}
  Token_stream(std::istream* p) : ip(std::move(p)) {}

  Token get();
  const Token& current();

 private:
  std::unique_ptr<std::istream> ip;
  Token ct;
};

void error(const std::string&);
