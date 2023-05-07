#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <tuple>

#define ASCII_TO_INT 48

std::tuple<int, int, int> checkSubMatrix(const std::vector<std::vector<int>>& matrix, const size_t& rows, const size_t& x, const size_t& y) {
	int size = 0;
	std::vector<std::vector<int>> subMatrix;

	// checking from the position where 1 was seen if it can be a subMatrix
	for (size_t yPos = y; yPos < rows; yPos++) {

		std::vector<int> xLine;
		for (size_t xPos = x; xPos < rows; xPos++) {

			if (matrix[yPos][xPos] == 1) {
				xLine.push_back(1);

				// according to first line calculate the size of the subMatrix
				if (yPos == y)
					size++;
			} else if(matrix[yPos][xPos] == 0 && !xLine.empty() || xPos + 1 == rows && !xLine.empty()) {
				subMatrix.push_back(xLine);
				xLine.clear();
				break;
			}
		}
	}

	// check if the size of y and y are persistantly the same.
	for (size_t i = 0; i < subMatrix.size() && !subMatrix[i].empty(); i++) {

		// if perhaps the first row was 3 times 1 and below was 2 times there's still a 2x2 matrix.
		if (subMatrix.size() != subMatrix[i].size() && subMatrix.size() < subMatrix[i].size()) {
			for (size_t x = subMatrix[i].size() - 1; x > subMatrix.size() && !subMatrix[i].empty(); x++) {
				subMatrix[i].pop_back();
				size--;
			}
		} else {
			// not a good matrix.
			return std::make_tuple(-1, -1, -1);
		}
	}
	return std::make_tuple(size, x, y);
}

int main() {
	std::cout << "Enter the number of rows for the matrix: ";

	// user input
	std::string input;
	std::getline(std::cin, input);

	// extracting integer from input and get the number in decimal (base 10).
	int rows = std::stoi(input, nullptr, 10);
	input.clear();

	std::vector<std::vector<int>> matrix;
	std::cout << "Enter the matrix row by row:\n";

	// constructing matrix 
	for (size_t i = 0; i < rows; i++) {

		// user input
		std::vector<int> line;
		std::getline(std::cin, input);
		std::stringstream ss(input);

		// i and num are only needed in for loop, therefore the anonymous struct. While ss.good && i < rows do i++.
		for (struct { size_t i = 0; int num; } s = { 0, 0 }; ss.good() && s.i < rows; s.i++) {
			ss >> s.num;
			if (s.num == 1 || s.num == 0) {
				line.push_back(s.num);
			} else {
				std::cout << "invalid input. Closing program.\n";
				return -1;
			}
		}
		ss.clear();
		matrix.push_back(line);
	}

	int subMatrixSize = 0, xPos = 0, yPos = 0;

	for (size_t y = 0; y < rows; y++) {
		for (size_t x = 0; x < rows; x++) {
			if (matrix[y][x] == 1) {
				std::tuple<int, int, int> result = checkSubMatrix(matrix, rows, x, y);
				if (std::get<0>(result) > subMatrixSize) {
					subMatrixSize = std::get<0>(result);
					xPos = std::get<1>(result);
					yPos = std::get<2>(result);
				}
			}
		}
	}

	std::cout << "The maximum square submatrix is at (" << xPos << ", " << yPos << ") with size " << subMatrixSize;

	return 0;
}