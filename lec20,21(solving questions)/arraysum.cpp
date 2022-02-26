#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> arrsum(vector<int>& a, int n, vector<int>& b, int m) {
    int n1 = 0, n2 = 0;
    for (int i = 0;i < n;i++) {
        n1 = (n1 * 10) + a[i];
    }
    for (int i = 0;i < m;i++) {
        n2 = (n2 * 10) + b[i];
    }
    cout << n1 << " " << n2 << endl;
    vector<int> ans;
    int n3 = n1 + n2;
    while (n3) {
        ans.push_back(n3 % 10);
        n3 /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> arrsum2(vector<int>& a, int n, vector<int>& b, int m) {
    int i1 = n - 1, i2 = m - 1;
    int carry = 0;
    vector<int> ans;
    while (i1 >= 0 && i2 >= 0) {
        int sum = a[i1--] + b[i2--] + carry;
        carry = 0;
        if (sum > 9) carry = 1;
        ans.push_back(sum % 10);
    }
    while (i1 >= 0) {
        int sum = a[i1--] + carry;
        carry = 0;
        if (sum > 9) carry = 1;
        ans.push_back(sum % 10);
    }
    while (i2 >= 0) {
        int sum = b[i2--] + carry;
        carry = 0;
        if (sum > 9) carry = 1;
        ans.push_back(sum % 10);
    }
    if (carry == 1)
        ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

void printarr(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;

}

int main() {
    vector<int> a = { 1,2,3,4 };
    vector<int> b = { 6 };
    vector<int> c = arrsum2(a, 4, b, 1);
    printarr(c, c.size());

    return 0;
}