#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string& a, int i) {
    if (i >= a.length() - 1 - i)
        return true;
    if (a[i] != a[a.length() - 1 - i])
        return false;
    return checkPalindrome(a, i + 1);
}

int main() {
    string a = "abbacabba";
    cout << checkPalindrome(a, 0) << endl;

    return 0;
}