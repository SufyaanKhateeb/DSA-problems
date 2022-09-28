#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // int a = 7;
    // int& r = a;
    // int* ptr = &a;

    // cout << "Normal: " << a << "\nRef: " << r << "\nPtr: " << *ptr << endl;

    int c = 7;
    int* ptr = &c;
    int& d = c;
    int*& a = ptr;
    // int& *b = &d; // not allowed, but could be read as pointer to a reference, this is not allowed

    cout << c << " " << d << " " << *a << endl;
    return 0;
}