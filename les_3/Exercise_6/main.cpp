#include <iostream>
#include <fstream>
#include <string>
#include <array>

constexpr std::array<char, 5> vowels{ 'a', 'e', 'i', 'o', 'u' };

int main() {

	// get user input
	std::cout << "prompt a file name: ";
	std::string file_name;
	std::getline(std::cin, file_name);

	// open file
	std::ifstream in_file(file_name);
	if (!in_file.is_open()) {
		std::cout << "in_file couln't open\n";
		return 1;
	}

	// count vowels
	int i = 0;
	char c = 0;
	while (in_file.get(c)) {
		for (auto& v : vowels) {
			if (v == c) {
				i++;
			}
		}
	}

	std::cout << "Number of vowels in the file: " << i << "\n";

	return 0;
}