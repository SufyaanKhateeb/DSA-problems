#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int i = 0;
    int n;
    int ans = 0;
    cin >> n;
    while (n) {
        int digit = n % 10;
        if (digit == 1)
            ans = ans + pow(2, i);
        i++;
        n /= 10;
    }
    cout << ans << endl;

    return 0;
}