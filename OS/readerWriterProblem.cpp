// R - R : No problem
// R - W : problem
// W - R : problem
// W - W : problem

// suppose that each reader reads for 3s and each writers writes for 3s 

#include <iostream>
#include <semaphore>
#include <chrono>
#include <thread>

using namespace std;

int readerCount = 0;
int buffer[] = { 1, 2, 3, 4, 5 }; // critical section
std::binary_semaphore smpWrt{ 1 }, smpRc{ 1 };

void readerfunc(string name) {
    smpRc.acquire();
    readerCount++;
    if (readerCount == 1) {
        smpWrt.acquire();
    }
    smpRc.release();

    std::cout << name << " is reading data." << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << name << " fininshed reading." << std::endl;
    smpRc.acquire();
    readerCount--;
    if (readerCount == 0) {
        smpWrt.release();
    }
    smpRc.release();
}

void writerFunc(string name) {
    smpWrt.acquire();
    std::cout << name << " is writing data." << std::endl;
    for (int i = 0; i < 5; i++) {
        buffer[i]++;
    }
    std::this_thread::sleep_for(2s);
    cout << "After Writing: ";
    for (int i = 0; i < 5; i++) {
        cout << buffer[i] << " ";
    }cout << endl;
    std::this_thread::sleep_for(1s);
    smpWrt.release();

}

int main() {
    // R - R : multiple readers are allowed
    // std::thread reader1(readerfunc, "Raj");
    // std::thread reader2(readerfunc, "Karan");
    // std::thread reader3(readerfunc, "Ahmed");

    // reader1.join();
    // reader2.join();
    // reader3.join();


    // R - W : writer can change data only after the reader has fininshed reading
    // std::thread reader1(readerfunc, "Raj");
    // std::thread writer1(writerFunc, "Chris");

    // reader1.join();
    // writer1.join();


    // W - R : reader can read data only after the writer has finished writing
    // std::thread writer1(writerFunc, "Chris");
    // std::thread reader1(readerfunc, "Raj");

    // writer1.join();
    // reader1.join();


    // W - W : any writer can write data only if no one else is writing data 
    std::thread writer1(writerFunc, "Chris");
    std::thread writer2(writerFunc, "Charles");

    writer1.join();
    writer2.join();

    return 0;
}