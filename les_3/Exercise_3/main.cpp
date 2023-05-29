#include <iostream>
#include <vector>
#include <string>

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2);

int main() {
    std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

	std::vector<int> numbers;
	for (int i = 1; i <= 20; i++) {
		numbers.push_back(i);
	}

    std::vector<int> intersectedVars = intersect<int>(primes, numbers);

    for (int i = 0; i < intersectedVars.size(); i++) {
		std::cout << "intersected var: " << intersectedVars[i] << "\n";
    }

    return 0;
}

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2) {
	std::vector<T> vector;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				vector.push_back(v2[j]);
			}
		}
	}
	return vector;
}
