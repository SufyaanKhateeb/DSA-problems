#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(int* arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot)
            cnt++;
    }
    int pivotindex = s + cnt;
    swap(arr[pivotindex], arr[s]);
    int i = s;
    int j = e;
    while (i < pivotindex && j > pivotindex) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotindex && j > pivotindex)
            swap(arr[i++], arr[j--]);
    }
    return pivotindex;
}

void quicksort(int* arr, int s, int e) {
    //base case
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main() {
    int arr[] = { 3, 2, 1, 9, 9 ,5, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}