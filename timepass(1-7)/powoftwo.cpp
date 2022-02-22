#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int power = log2(n);
    cout << power << endl;
    if (pow(2, power) == n) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}