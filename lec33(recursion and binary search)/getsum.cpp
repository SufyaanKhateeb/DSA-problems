#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getsum(int* arr, int size) {
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    return arr[0] + getsum(arr + 1, size - 1);
}

int main() {
    int arr[] = { 3, 5, 4, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = getsum(arr, size);
    cout << "Sum is: " << ans;
    return 0;
}