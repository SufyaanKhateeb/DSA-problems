// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition
// 6. If some thread wants to wait on some condition it has to do these things
//     a. Acquire the mutex lock
//     b. Execute wait, wait_for, wait_until. The wait operation atomically releases the mutex.
//     c. When the condition variable is notified. The thread is awakened, and the mutex is automatically reacquired.
//        If the condition is satisfied then it moves ahead or b step is repeated. Same happens in case of spurious notifications.

// SLEEP :
// 0. “I’m done with my timeslice, and please don’t give me another one for at least n milliseconds.”  The OS doesn’t even try to schedule the sleeping thread until requested time has passed.
// 1. It will keep the lock and sleep.
// 2. Sleep is directly to thread, it is a thread function.

// WAIT :
// 0. “I’m done with my timeslice. Don’t give me another timeslice until someone calls notify().” As with sleep(), the OS won’t even try to schedule your task unless someone calls notify() (or one of a few other wakeup scenarios occurs).
// 1. It releases the lock and wait.
// 2. Wait is on condition variable, it is like there is a condition variable in a thread and wait is applied to that CV but it ends up puting thread in waiting state.

#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

std::mutex m;
std::condition_variable cv;
int balance = 0;

void addMoney(int money) {
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Balance after adding amount: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [] {
        return (balance != 0) ? true : false;
        });
    cout << "Current balance: " << balance << endl;
    if (money <= balance) {
        cout << "Balance after withdrawing amount: " << balance - money << endl;
        balance -= money;
    }
    else {
        cout << "Insufficient balance." << endl;
    }
}

int main() {
    std::thread t1(withdrawMoney, 500);
    std::thread t2(withdrawMoney, 30);
    std::thread t3(addMoney, 500);
    std::thread t4(addMoney, 1000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}