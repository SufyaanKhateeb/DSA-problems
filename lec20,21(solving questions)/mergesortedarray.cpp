#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergesorted(int arr1[], int arr2[], int arr3[], int n, int m, int s) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n) arr3[k++] = arr1[i++];
    while (j < m) arr3[k++] = arr2[j++];
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}

int main() {
    int arr1[] = { 2 ,4 ,5, 7, 10 };
    int arr2[] = { 3 ,6 ,9, 12, 20 };
    int arr3[10] = { 0 };
    mergesorted(arr1, arr2, arr3, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]), sizeof(arr3) / sizeof(arr3[0]));
    printarr(arr3, 10);

    return 0;
}