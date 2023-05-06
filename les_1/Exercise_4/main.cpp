#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <array>

const int SIZE = 4;
const int ROWS = 3;

// check if the input are actual doubles and not strings. If true it'll return the numbers as array in a tuple.
std::tuple<bool, std::array<double, SIZE>> getNumbers(const std::string input) {
    std::istringstream iss(input);
    std::array<double, SIZE> numbers;

    if (iss >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3])
        return std::make_tuple(true, numbers);
    else
        return std::make_tuple(false, numbers);
}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
    double sum = 0;
    for (size_t i = 0; i < rowSize; i++) {
        sum += m[i][columnIndex];
    }
    return sum;
}

int main() {
    double matrix[ROWS][SIZE];

    std::cout << "Enter a 3-by-4 matrix row by row:\n";
    for (size_t i = 0; i < ROWS; i++) {

        // input from user
        std::string input;
        std::getline(std::cin, input);

        // check if input is valid
        if (std::get<bool>(getNumbers(input))) {

            // get input in array of 4 and set every value accordingly in matrix
            std::array<double, SIZE> numbers = std::get<std::array<double, 4>>(getNumbers(input));
            for (size_t j = 0; j < SIZE; j++) {
                matrix[i][j] = numbers[j];
            }
        }
        else {
            std::cout << " Invalid input, exiting program...\n";
            return 1;
        }
    }

    // print sum of each column
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << "sum of the elements at column " << i << " is " << sumColumn(matrix, ROWS, i) << "\n";
    }
    return 0;
}