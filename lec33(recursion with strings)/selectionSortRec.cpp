#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void selectionsort(int* arr, int i, int n) {
    if (i >= n - 1)
        return;
    for (int j = i + 1; j < n; j++) {
        if (arr[i] > arr[j])
            swap(arr[i], arr[j]);
    }
    return selectionsort(arr, i + 1, n);
}

int main() {
    int arr[] = { 3, 5, 1, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}