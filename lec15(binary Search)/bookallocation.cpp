#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isallocationpossible(vector<int>& arr, int n, int m, int mid) {
    int stdcount = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > mid) {
            stdcount++;
            if (stdcount > m || arr[i] > mid) return false;
            pages = arr[i];
        }
        else {
            pages += arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    if (n < m)
        return ans;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isallocationpossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = { 5, 17, 100, 11 };
    int n = 4;
    int m = 4;
    cout << allocateBooks(arr, n, m);

    return 0;
}