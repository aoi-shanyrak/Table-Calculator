#include "lexer.hpp"

void error(const std::string& s) {
  std::cerr << "error: " << s << std::endl;
}

const Token& Token_stream::current() {
  return ct;
}

Token Token_stream::get() {
  char ch;

  do {
    if (!ip->get(ch)) return ct = {Kind::end};
  } while (ch != '\n' and isspace(ch));

  switch (ch) {
    case '\n':
    case ';': return ct = {Kind::end};
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=': return ct = {static_cast<Kind>(ch)};
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      ip->putback(ch);
      *ip >> ct.number_value;
      ct.kind = Kind::number;
      return ct;
    default:
      if (isalpha(ch)) {
        ct.string_value = ch;
        while (ip->get(ch) and isalnum(ch)) ct.string_value += ch;
        ct.kind = Kind::name;
        return ct;
      }
      error("bad token");
      return ct = {Kind::end};
  }
}
