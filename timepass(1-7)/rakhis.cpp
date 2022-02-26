#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = { 1, -2, 2 };
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] + sum > 0) {
            sum += arr[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}