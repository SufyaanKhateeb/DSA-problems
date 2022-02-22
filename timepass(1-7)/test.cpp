#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int ans = 0;
    int i = 0;
    cin >> n;
    while (n) {
        int digit = n & 1;
        ans = digit * pow(10, i) + ans;
        i++;
        n = n >> 1;
    }
    cout << ans << endl;
    return 0;
}