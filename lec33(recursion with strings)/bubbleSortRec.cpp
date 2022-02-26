#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubblesort(int* arr, int n) {
    if (n == 0 || n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    return bubblesort(arr, n - 1);
}

int main() {
    int arr[] = { 3, 5, 1, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}