#include <iostream>
#include <chrono>
#include <algorithm>
#include <array>

#include "Homework.h"

const int SIZE = 100000;

int main() {
    int numbers[SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100000;
    }

    StopWatch stopwatch;
    std::sort(numbers, numbers + SIZE);
    stopwatch.stop();

    std::cout << "Time elapsed: " << stopwatch.getElapsedTime() << " milliseconds\n";
    return 0;
}