#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> subsequences(string str) {
    vector<string> ans;
    int size = str.size();
    for (int num = 1; num < pow(2, size); num++) {
        string temp = "";
        for (int i = 0; i < size; i++) {
            if (num & (1 << i)) {
                temp += str[i];
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    string str = "bbb";
    vector<string> ans = subsequences(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }cout << endl;


    return 0;
}
