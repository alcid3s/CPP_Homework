#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// func<returntype(var1, var2)> name
typedef std::function<int(int, int)> MyLambda;

MyLambda sum = [](int x, int y) {
	return x + y;
};

int main() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	int result = 0;

	std::for_each(numbers.begin(), numbers.end(), [&result](int num) {
		result = sum(result, num);
		});

	std::cout << "Result: " << result << "\n";

	return 0;
}