#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool mybinary(vector<vector<int>>& matrix, int target, int row) {
    if(row<0) return false;
    int s = 0;
    int e = matrix[row].size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (matrix[row][mid] == target)
            return true;
        if (matrix[row][mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return false;
}

void searchMatrix(vector<vector<int>>& matrix, int target) {
    int s = 0;
    int e = matrix.size() - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (matrix[mid][0] == target){
            cout << "True" << endl;
            break;
        }
        if (matrix[mid][0] > target)
            e = mid;
        else
            s = mid + 1;
    }
    cout << s << " " << e << endl;
    cout << mybinary(matrix, target, e) << " " << mybinary(matrix, target, e - 1) << endl;
}

int main() {
    // vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    vector<vector<int>> matrix = { {1} };
    searchMatrix(matrix, 0);

    return 0;
}