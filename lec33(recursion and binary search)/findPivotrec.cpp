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

int getPivot(int* input, int s, int e) {
    if (s >= e)
        return e;
    int mid = s + (e - s) / 2;
    if (input[mid] >= input[0])
        return getPivot(input, mid + 1, e);
    else
        return getPivot(input, s, mid);
}

int findPivot(int* input, int n)
{
    int s = 0;
    int e = n - 1;
    int ans = getPivot(input, s, e);
    return ans;
}

int main() {
int arr[] = {  };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 0;
    int ans = findPivot(arr, size);
    cout << "Found at index: " << ans;
    return 0;
}