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

bool linearSearchrec(int* arr, int size, int key) {
    printarr(arr, size);
    cout << endl;
    if (size == 0)
        return false;
    return arr[0] == key || linearSearchrec(arr + 1, size - 1, key);
}

int main() {
    int arr[] = { 3, 5, 3, 6, 7, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    bool ans = linearSearchrec(arr, size, key);
    cout << ans;
    return 0;
}