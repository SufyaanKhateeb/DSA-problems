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

int fbs(int* input, int s, int e, int val, int ans) {
    if (s > e)
        return ans;
    int mid = s + (e - s) / 2;
    if (input[mid] == val) {
        ans = mid;
        return fbs(input, s, mid - 1, val, ans);
    }
    if (input[mid] < val)
        return fbs(input, mid + 1, e, val, ans);
    else
        return fbs(input, s, mid - 1, val, ans);
}

int lbs(int* input, int s, int e, int val, int ans) {
    if (s > e)
        return ans;
    int mid = s + (e - s) / 2;
    if (input[mid] == val) {
        ans = mid;
        return lbs(input, mid + 1, e, val, ans);
    }
    if (input[mid] < val)
        return lbs(input, mid + 1, e, val, ans);
    else
        return lbs(input, s, mid - 1, val, ans);
}
void binarySearch(int* input, int n, int val)
{
    int s = 0;
    int e = n - 1;
    int first = fbs(input, s, e, val, -1);
    int last = lbs(input, s, e, val, -1);
    cout << "First occurance: " << first << endl;
    cout << "Last occurance: " << last << endl;
}

int main() {
    int arr[] = { 3, 4, 4, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    binarySearch(arr, size, key);
    return 0;
}