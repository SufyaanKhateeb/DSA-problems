#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;
}

int main() {
    vector<int> arr = { 5,4,1,2,3 };
    // int size = sizeof(arr) / sizeof(arr[0]);
    printarr(arr, arr.size());
    sort(arr.begin(), arr.end());
    printarr(arr, arr.size());
    cout << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}
