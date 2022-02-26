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

int getpeak(int* input, int s, int e) {
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (input[mid] > input[mid + 1] && input[mid] > input[mid - 1])
        return mid;
    if (input[mid - 1] < input[mid] && input[mid] < input[mid + 1])
        return getpeak(input, mid + 1, e);
    else
        return getpeak(input, s, mid - 1);
}
int findPeak(int* input, int n)
{
    int s = 0;
    int e = n - 1;
    int ans = getpeak(input, s, e);
    return ans;
}

int main() {
    int arr[] = { 3, 4, 2, 1 }; //mountain array
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = findPeak(arr, size);
    cout << "Peak at index: " << ans;
    return 0;
}