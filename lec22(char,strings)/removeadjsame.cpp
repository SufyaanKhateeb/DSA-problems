#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "aaaa";
    int i = 0;
    int size = s.size();
    while(i < size-1) {
        if (s[i] == s[i + 1] && i == 0) {
            s.erase(i, 2);
            size -= 2;
            i -= 1;
            cout << "size: " << s.size() << endl;
        }
        else if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            size -= 2;
            i -= 2;
        }
        i++;
    }

    cout << s << endl;

    return 0;
}