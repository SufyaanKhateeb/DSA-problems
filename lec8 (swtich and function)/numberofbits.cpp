#include <iostream>

using namespace std;

int noofbits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int a, b;
    cout << "Enter the two numbers: ";
    cin >> a >> b;
    cout << "The total number of set bits is " << noofbits(a) + noofbits(b) << endl;
    return 0;
}