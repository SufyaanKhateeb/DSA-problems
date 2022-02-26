#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    int mask = 1;
    mask = mask << 31;
    cin >> n;
    // n = -n;
    int count = 32;
    while (count) {
        // cout << mask << " = ";
        // cout << (n & mask) << endl;
        if ((mask & n) == mask) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        count--;
        mask = mask >> 1;
    }

    return 0;
}