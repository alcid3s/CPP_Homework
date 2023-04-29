#include <iostream>
#include <string>

#define charToInt 97

void count(const char s[], int counts[]) {
  for(int i = 0; i < 26; i++)
  {
    counts[i] = 0;
  }

  for(int i = 0; i < 26; i++) {
    char c = tolower(s[i]);
    if(c >= 'a' && c <= 'z') {
      int index = c - charToInt;
      counts[index]++;
    }
  }
}

int main() {
  char text[100];
  int counts[26];
  std::cout << "enter a string: \n";
  std::cin.getline(text, 100);

  count(text, counts);

  for(int i = 0; i < 26; i++) {
    if(counts[i] == 0) {
      continue;
    }
    char c = charToInt + i;
    std::cout << c << ": " << counts[i] << " times.\n";
  }
}
