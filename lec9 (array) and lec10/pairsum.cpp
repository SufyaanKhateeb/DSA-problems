#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                vector<int> sub;
                sub.push_back(min(arr[i], arr[j]));
                // cout << arr[i] << " " << arr[j] << endl;
                sub.push_back(max(arr[i], arr[j]));
                ans.push_back(sub);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> arr = { 2, -3, 3, 3, -2 };
    vector<vector<int>> ans = pairSum(arr, 0);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}