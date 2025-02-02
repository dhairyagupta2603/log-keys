#include "sibyl.hpp"

#include <iostream>

auto sibyl::print(std::string_view greeting) -> void {
  std::cout << greeting << '\n';
}