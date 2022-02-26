#include <iostream>

using namespace std;

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    int n;
    cin >> n;
    if (isEven(n))
        cout << "number is even" << endl;
    else
        cout << "number is odd" << endl;
    return 0;
}