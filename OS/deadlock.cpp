// deadlock occurs when every processes/threads wants to acquire a lock on something that has been acquired already by other processes/threads threfore this leads to condition where no process/thread can complete execution.
// deadlock doesn't happen easily because today's processors are very fast, but it may occur in the below case. Observe that the functions are having infinite loops to force the deadlock condition
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;

std::mutex m1, m2;

void fun1() {
    while (true) {
        m1.lock();
        m2.lock();
        std::cout << "I am in function 1." << std::endl;
        std::this_thread::sleep_for(1s);
        m1.unlock();
        m2.unlock();
    }
}

void fun2() {
    while (true) {
        m2.lock();
        m1.lock();
        std::cout << "I am in function 2." << std::endl;
        std::this_thread::sleep_for(1s);
        m1.unlock();
        m2.unlock();
    }
}

int main() {
    std::thread t1(fun1), t2(fun2);

    t1.join();
    t2.join();

    return 0;
}