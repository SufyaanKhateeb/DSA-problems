#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;

}

bool check(vector<int>& nums) {
    int i = 0;
    while (i < nums.size() - 1 && nums[i] < nums[i + 1])
        i++;
    cout << i << endl;
    if (i == nums.size() - 1)
        return true;
    vector<int> c(nums);
    sort(c.begin(), c.end());
    printarr(c, c.size());
    reverse(nums.begin(), nums.begin() + i + 1);
    reverse(nums.begin() + i + 1, nums.end());
    reverse(nums.begin(), nums.end());
    printarr(nums, nums.size());
    return c == nums;
}

int main() {
    vector<int> nums = { 3,4,5,1,2 };
    cout << check(nums) << endl;

    return 0;
}