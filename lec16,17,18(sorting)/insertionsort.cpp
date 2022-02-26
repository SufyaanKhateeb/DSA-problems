#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void insertionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j - 1] < arr[j])
                break;
            else
                swap(arr[j - 1], arr[j]);
        }
    }
}
void intersionsort(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
            else
                break;
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
    insertionsort(arr, n);
    printarr(arr, n);


    return 0;
}