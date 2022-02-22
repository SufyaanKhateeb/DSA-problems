#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findpower(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int temp = findpower(a, b / 2);
    if (b % 2 == 0)
        return temp * temp;
    else
        return a * temp * temp;
}

int fastexponentiation(int res, int a, int b) {
    if (b <= 0)
        return res;
    if (b & 1)
        return fastexponentiation(res * a, a * a, b >> 1);
    else
        return fastexponentiation(res, a * a, b >> 1);
}

int fastexp(int a, int b) {
    return fastexponentiation(1, a, b);
}

int main() {
    int a, b;
    cout << "Enter the a and b values: ";
    cin >> a >> b;
    cout << "Power is: " << findpower(a, b) << endl;
    cout << "Power using fast Exponentiation: " << fastexp(a, b) << endl;

    return 0;
}