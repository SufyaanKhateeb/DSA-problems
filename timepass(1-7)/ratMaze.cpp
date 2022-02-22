#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cangodown(int i, int j, vector<vector<int>>& m, vector<vector<bool>>& visited, int n) {
    if (i + 1 != n && m[i + 1][j] == 1 && !visited[i + 1][j])
        return true;
    return false;
}
bool cangoleft(int i, int j, vector<vector<int>>& m, vector<vector<bool>>& visited, int n) {
    if (j - 1 != -1 && m[i][j - 1] == 1 && !visited[i][j - 1])
        return true;
    return false;
}
bool cangoright(int i, int j, vector<vector<int>>& m, vector<vector<bool>>& visited, int n) {
    if (j + 1 != n && m[i][j + 1] == 1 && !visited[i][j + 1])
        return true;
    return false;
}
bool cangoup(int i, int j, vector<vector<int>>& m, vector<vector<bool>>& visited, int n) {
    if (i - 1 != -1 && m[i - 1][j] == 1 && !visited[i - 1][j])
        return true;
    return false;
}
void getallpaths(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, vector<vector<bool>>& visited, string str) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(str);
        return;
    }
    if (cangodown(i, j, m, visited, n)) {
        str += 'D';
        visited[i + 1][j] = true;
        getallpaths(i + 1, j, m, n, ans, visited, str);
        str.pop_back();
        visited[i + 1][j] = false;
    }
    if (cangoleft(i, j, m, visited, n)) {
        str += 'L';
        visited[i][j - 1] = true;
        getallpaths(i, j - 1, m, n, ans, visited, str);
        str.pop_back();
        visited[i][j - 1] = false;
    }
    if (cangoright(i, j, m, visited, n)) {
        str += 'R';
        visited[i][j + 1] = true;
        getallpaths(i, j + 1, m, n, ans, visited, str);
        str.pop_back();
        visited[i][j + 1] = false;
    }
    if (cangoup(i, j, m, visited, n)) {
        str += 'U';
        visited[i - 1][j] = true;
        getallpaths(i - 1, j, m, n, ans, visited, str);
        str.pop_back();
        visited[i - 1][j] = false;
    }
}
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<bool> temp(n, false);
    vector<vector<bool>> visited(n, temp);
    string str = "";
    visited[0][0] = true;
    getallpaths(0, 0, m, n, ans, visited, str);
    return ans;
}

int main() {
    vector<vector<int>> m = { {1, 0, 0, 0},
                            {1, 1, 0, 1},
                            {1, 1, 0, 0},
                            {0, 1, 1, 1} };
    vector<string> ans = findPath(m, 4);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}