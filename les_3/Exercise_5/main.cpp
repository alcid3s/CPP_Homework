#include <iostream>
#include <fstream>
#include <string>

const std::string file_name = "Exercise3_5.txt";

int main() {
	std::ifstream in_file(file_name);
	if (!in_file.is_open()) {
		std::cout << "in_file couln't open\n";
		return 1;
	}

	int i = 0;
	for (char c = 0; in_file.get(c); i++);

	std::cout << "Total number of characters in the file: " << i << "\n";
	std::ofstream out_file(file_name, std::ios::app);
	if (!out_file.is_open()) {
		std::cout << "out_file couln't open\n";
		return 1;
	}

	out_file << "\n\nTotal number of characters in the file: " << i;
	return 0;
}

