#include <iostream>

using namespace std;

int fact(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r) {
    int nume = fact(n);
    int deno = fact(r) * fact(n - r);
    return nume / deno;
}

int main() {
    int n, r;
    cout << "Enter the values of n and r: ";
    cin >> n >> r;
    cout << "nCr is " << nCr(n, r) << endl;

    return 0;
}