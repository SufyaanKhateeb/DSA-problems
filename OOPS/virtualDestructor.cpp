#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class base {
    public:
    base() {
        cout << "base constructor" << endl;
    }
    virtual ~base() {
        cout << "base destructor" << endl;
    }
};

class derived : public base {
    public:
    derived() {
        cout << "derived constructor" << endl;
    }
    ~derived() {
        cout << "derived destructor" << endl;
    }
};

int main() {
    base * b = new derived();
    delete b;

    return 0;
}