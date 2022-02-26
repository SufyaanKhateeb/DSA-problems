#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1;k < arr.size(); k++) {
                if (arr[i] + arr[j] + arr[k] == K) {
                    vector<int> sub;
                    sub.push_back(arr[i]);
                    sub.push_back(arr[j]);
                    sub.push_back(arr[k]);
                    sort(sub.begin(), sub.end());
                    ans.push_back(sub);
                }
            }
        }
    }
    vector<vector<int>>::iterator iter;
    iter = unique(ans.begin(), ans.end());
    ans.resize(iter - ans.begin());
    return ans;
}

int main() {
    vector<int> arr = { 10, 5, 5, 5, 2 };
    vector<vector<int>> ans = findTriplets(arr, 5, 12);
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}