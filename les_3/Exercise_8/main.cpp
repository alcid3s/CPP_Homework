#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define ascii_numbers 48

const std::string file_name = "Exercise3_8.txt";

int main() {
	std::ifstream in_file(file_name);

	if (!in_file.is_open()) {
		std::cout << "in_file couln't open\n";
		return 1;
	}
	
	std::vector<int> numbers;

	int num;

	while (in_file >> num) {
		numbers.insert(numbers.begin(), num);
	}

	std::ofstream out_file("Exercise3_8.txt", std::ios::trunc);

	for (auto& n : numbers)
	{
		out_file << n << " ";
		std::cout << "Wrote " << n << " to file\n";
	}
	return 0;
}