#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string sub(string s, int start, int l) {
    string str;
    for (int i = 0; i < l; i++) {
        str += s[start + i];
    }
    return str;
}

int main() {
    // while(s.length() != 0 && s.find(part) < s.length()) {
    //     s.erase(s.find(part), part.length());
    // }
    // return s;
    string s = "daabcbaabcbc";
    string part = "abc";
    string x = s;
    int n = s.length(), m = part.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j++] = s[i];
        if (j >= m) cout << j << " " << sub(x, j - m, m) << endl;
        if (j >= m && sub(x, j - m, m) == part) {
            // cout << sub(s, j - m, m) << endl;
            j -= m;
        }
    }
    cout << sub(x, 0, j);

    return 0;
}