#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canplacecows(vector<int>& stalls, int n, int k, int mid) {
    int cowcount = 1;
    int lastpos = 0;
    for (int i = 0; i < n; i++) {
        if (stalls[i] - stalls[lastpos] >= mid) {
            cowcount++;
            if (cowcount == k)  return true;
            lastpos = i;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k)
{
    int s = 0;
    sort(stalls.begin(), stalls.end());
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (canplacecows(stalls, stalls.size(), k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = { 4, 2, 1, 3, 6 };
    int k = 2;
    int m = 5;
    cout << aggressiveCows(stalls, k);

    return 0;
}