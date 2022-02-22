#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<char> chars = { 'a','a','b','b','c','c','c' };
    string ans = "";
    for (int i = 0; i < chars.size(); i++) {
        int count = 1;
        while (i != chars.size() - 1 && chars[i] == chars[i + 1]) {
            count++;
            i++;
        }
        if (count == 1)
            ans += chars[i];
        else {
            string temp = "";
            while (count) {
                temp = to_string(count % 10) + temp;
                count /= 10;
            }
            ans = ans + chars[i] + temp;
        }
    }
    cout << ans.size() << ' ' << ans << endl;

    return 0;
}