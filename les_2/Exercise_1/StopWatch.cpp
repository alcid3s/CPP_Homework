#include "StopWatch.h"

StopWatch::StopWatch()
{
    start();
}

void StopWatch::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void StopWatch::stop()
{
    endTime = std::chrono::high_resolution_clock::now();
}

unsigned long long StopWatch::getElapsedTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}