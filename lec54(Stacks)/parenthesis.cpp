#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string expression = "[()]{}{[()()]()}";
    unordered_map<char,int> symbols = {{'{',-1},{'(',-2},{'[',-3},{'}',1},{')',2},{']',3}};
    stack<char> st;
    for(char i: expression) {
        if(symbols[i] < 0) {
            st.push(i);
        } else {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if(symbols[i] + symbols[ch] != 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}