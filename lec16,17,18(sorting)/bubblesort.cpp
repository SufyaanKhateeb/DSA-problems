#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubblesort(int arr[], int n) {
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j+1]) {
                swap(arr[i], arr[j]);
                flag = true;
            }
        }
        if(!flag)
            break;
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
    bubblesort(arr, n);
    printarr(arr, n);


    return 0;
}