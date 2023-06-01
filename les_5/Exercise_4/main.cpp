#include <iostream>
#include <thread>
#include <semaphore>

std::string text;
std::binary_semaphore sem1(0);
std::binary_semaphore sem2(0);
std::binary_semaphore sem3(0);

void Thread(int threadId, std::binary_semaphore& currentSem, std::binary_semaphore& nextSem, const std::string& message)
{
    currentSem.acquire();
    text += message;
    nextSem.release();
}

int main()
{
    std::thread t1(Thread, 1, std::ref(sem1), std::ref(sem2), "text thread 1\n");
    std::thread t2(Thread, 2, std::ref(sem2), std::ref(sem3), "text thread 2\n");
    std::thread t3(Thread, 3, std::ref(sem3), std::ref(sem1), "text thread 3\n");

    sem1.release();

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Result:\n" << text << "\n";

    return 0;
}