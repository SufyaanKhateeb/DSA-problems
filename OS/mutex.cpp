// Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusion

// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

// std::try_lock(m1, m2, m3, m4, .... mn) // check the video of cppnuts 
// 0. std::try_lock() tries to lock all the mutexes passed in it one by one in given order.
// 1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.

#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include <mutex>

using namespace std;

int amount = 0;
std::mutex m;

void addMoney() {
    m.lock();
    amount++;
    m.unlock();
}

int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();


    cout << "Amount: " << amount << endl;

    return 0;
}