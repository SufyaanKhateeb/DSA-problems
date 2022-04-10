#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "Sufyaan";
    stack<char> s;
    for (auto& i : a) {
        s.push(i);
    }
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << "Ans: " << ans << endl;
    return 0;
}