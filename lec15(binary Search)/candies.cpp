#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool possible(vector<vector<int>>& arr, int n, int B, int mid) {
    int frnd = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 1; j <= arr[i][0]; j++) {
            if (arr[i][j] <= mid) sum += arr[i][j];
            if (sum > B) return false;
        }
    }
    cout << "Sum: " << sum << endl;
    return sum <= B;
}

int findMaxX(int n, vector<vector<int>>& arr, int B)
{
    int s = 0;
    int e = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 1;j <= arr[i][0];j++) {
            if (e < arr[i][j])
                e = arr[i][j];
        }
    }
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (possible(arr, n, B, mid)) {
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
    vector<vector<int>> arr = { {3,1,2,3},{3,4,2,3},{3,1,10,2} };
    int n = 3;
    int B = 20;
    cout << findMaxX(n, arr, B) << endl;

    return 0;
}