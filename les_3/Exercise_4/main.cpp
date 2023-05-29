#include <iostream>
#include <vector>

template<typename T>
void intersect(std::vector<T>& v);


int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 5, 4, 9, 7, 1, 9, 2 };

    intersect<int>(numbers);

    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << "\n";
    }

    return 0;
}

template<typename T>
void intersect(std::vector<T>& v) {
    int size = v.size();
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[i] == v[j] && i != j) {
                v.erase(v.begin() + i);
                size--;
            }
        }
    }
    v.resize(size);
}

