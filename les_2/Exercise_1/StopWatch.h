#pragma once
#include <chrono>

class StopWatch {
public:
    // constructor
    StopWatch();

    // methods
    void start();
    void stop();
    unsigned long long getElapsedTime();

    // getters
    std::chrono::high_resolution_clock::time_point getStartTime() {
        return startTime;
    }
    std::chrono::high_resolution_clock::time_point getEndTime() {
        return endTime;
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
};