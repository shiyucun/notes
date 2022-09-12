
#include <iostream>

#include "add.hpp"
#include "sub.hpp"
#include "multi.hpp"

int main() {
  std::cout << Add(1, 2) << std::endl;
  std::cout << Multi(1, 2) << std::endl;
  std::cout << Sub(1, 2) << std::endl;

  return 0;
}
