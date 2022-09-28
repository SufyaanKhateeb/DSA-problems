// why we need initializer list? https://youtu.be/1nfuYMXjZsA

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class myobj {
public:
    myobj() {
        cout << "Default Constructor" << endl;
    }
};

class Temp1 {
    myobj a;
public:
    Temp1(myobj b) :a(b) {}
};

class Temp2 {
    myobj a;
public:
    Temp2(myobj b) {
        a = b;
    }
};

int main() {
    myobj b;
    Temp1 t1(b);
    // Temp2 t2(b);

    return 0;
}