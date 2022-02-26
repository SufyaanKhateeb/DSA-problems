#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void insertionsort(int* arr, int i, int n) {
    if (i >= n - 1)
        return;
    for (int j = i + 1; j > 0; j--) {
        if (arr[j] < arr[j - 1])
            swap(arr[j], arr[j - 1]);
    }
    return insertionsort(arr, i + 1, n);
}

int main() {
    int arr[] = { 3, 5, 1, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}