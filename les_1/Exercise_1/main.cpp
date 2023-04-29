#include <iostream>
#include <string>
#include <cstdio>

bool search(std::string& s, char& key) {
  return s.find(key) != std::string::npos;
}

int main() {
  std::cout << "Welcome user, please enter some text:\n";
  std::string input;
  std::getline(std::cin, input);

  std::cout << "Now give a character to look for\n";
  char key = getchar();

  if(search(input, key)) {
    std::cout << '[' << input << "] contains '" << key << '\'' << "\n";
  } else {
    std::cout << '[' << input << "] doesn't contain '" << key << '\'' << "\n";
  }

  return 0;
}
