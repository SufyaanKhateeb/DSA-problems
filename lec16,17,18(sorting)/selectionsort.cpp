#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}

int main() {
    int arr[] = { 4, 5, 1, 0, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    printarr(arr, n);


    return 0;
}