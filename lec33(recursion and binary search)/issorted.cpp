#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool checksorted(int* arr, int size) {
    printarr(arr, size);
    cout << endl;
    if (size <= 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    return checksorted(arr + 1, size - 1);
}

int main() {
    int arr[] = { 3, 5, 4, 6, 7 };
    vector<int> cool = { 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bool ans = checksorted(arr, size);
    cout << ans;
    return 0;
}