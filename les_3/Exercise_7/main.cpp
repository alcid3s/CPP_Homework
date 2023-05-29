#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define ascii_numbers 48

const std::string file_name = "Exercise3_7.txt";

int get_sum(std::vector<int>& numbers) {
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers.at(i);
	}
	return sum;
}

double get_average(std::vector<int>& numbers) {
	double average = get_sum(numbers);
	return average / numbers.size();
}

int get_product(std::vector<int>& numbers) {
	int product = 1;
	for (int i = 0; i < numbers.size(); i++) {
		product *= numbers.at(i);
	}
	return product;
}

int main() {
	std::ifstream file(file_name);

	if (!file.is_open()) {
		std::cout << "file couln't open\n";
		return 1;
	}

	std::vector<int> numbers;
	char c = 0;
	while (file.get(c)) {
		// changing the ascii value of the number to an actual numeric value.
		if (c - ascii_numbers >= 0 && c - ascii_numbers <= 9) {
			numbers.push_back(c - ascii_numbers);
		}
	}
 
	std::cout << "sum: " << get_sum(numbers) << ", average: " << get_average(numbers) << ", product: " << get_product(numbers) << "\n";
	return 0;
}