#include <iostream>
#include <string>

#include "error.hpp"

void Error::error(const std::string& s) {
  std::cerr << "error: " << s << std::endl;
}
