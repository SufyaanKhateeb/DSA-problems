// There are five types
// 1. using function pointers
// 2. using lambda functions
// 3. using functors (skipping this beacause I don't know)
// 4. using non static member functions (non static functions(functions of particular objects) in classes)
// 5. using static member functions (static functions in classes)
#include <iostream>
#include <bits/stdc++.h>
#include <thread>

using namespace std;

// 1. function pointers
// void fun(int x) {
//     while(x--) {
//         cout << x << endl;
//     }
// }

// int main() {
//     std::thread t1(fun, 5);
//     t1.join();

//     return 0;
// }


// 2. lambda functions

// int main() {
//     auto fun = [](int x) {          //labmda function, we can place this function inside the thread declaration only if we want.
//         while (x--) {
//             cout << x << endl;
//         }
//     };
//     std::thread t1(fun, 5);
//     t1.join();

//     return 0;
// }


// 4. non static member functions
// class Base {
// public:
//     void fun(int x) {
//         while (x--) {
//             cout << x << endl;
//         }
//     }
// };

// int main() {
//     Base b;
//     std::thread t1(&Base::fun, &b, 5);
//     t1.join();

//     return 0;
// }


// 5. static member functions
class Base {
public:
    static void fun(int x) {
        while (x--) {
            cout << x << endl;
        }
    }
};

int main() {
    std::thread t1(&Base::fun, 5);
    t1.join();

    return 0;
}
