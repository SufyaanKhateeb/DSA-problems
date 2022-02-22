#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reversestr(string& a, int i, int j) {
    if (i >= j)
        return;
    swap(a[i], a[j]);
    return reversestr(a, i + 1, j - 1);
}

int main() {
    string a = "abcde";
    cout << a << endl;
    reversestr(a, 0, a.length() - 1);
    cout << a << endl;

    return 0;
}