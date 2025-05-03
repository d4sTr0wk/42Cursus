#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return (1);
  }
  std::string str1;
  for (size_t i = 1; i < (size_t)argc; i++) {
    for (size_t j = 0; argv[i][j] != '\0'; j++) {
      str1 += std::toupper(argv[i][j]);
    }
  }
  std::cout << str1 << std::endl;
  return (0);
}