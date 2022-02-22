#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(int* arr, int size) {
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bs(int* input, int s, int e, int val) {
    if (s > e)
        return -1;
    printarr(input, e);
    int mid = s + (e - s) / 2;
    cout << "Mid is: " << input[mid] << endl;
    if (input[mid] == val)
        return mid;
    if (input[mid] < val)
        return bs(input, mid + 1, e, val);
    else
        return bs(input, s, mid - 1, val);
}
int binarySearch(int* input, int n, int val)
{
    int s = 0;
    int e = n - 1;
    int ans = bs(input, s, e, val);
    return ans;
}

int main() {
    int arr[] = { 3, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 0;
    int ans = binarySearch(arr, size, key);
    cout << "Found at index: " << ans;
    return 0;
}