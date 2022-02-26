#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reversestr(string s, int n) {
    int st = 0, e = n - 1;
    while (st < e) {
        swap(s[st++], s[e--]);
    }
    return s;
}

int main() {
    string s = "N2 i&nJA?a& jnI2n";
    // string c;
    // for (int i = 0; i < s.length(); i++) {
    //     if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 48 && s[i] <= 57))
    //         c += toupper(s[i]);
    // }
    // // cout << c << endl;
    // string d = reversestr(c, c.length());
    // if (d == c)
    //     cout << "True" << endl;
    // else
    //     cout << "False" << endl;


    //another approach
    int i = 0;
    int e = s.length()-1;
    while(i<e) {
        if(!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 48 && s[i] <= 57))) {
            i++;
            continue;
        }
    	if(!((s[e] >= 97 && s[e] <= 122) || (s[e] >= 65 && s[e] <= 90) || (s[e] >= 48 && s[e] <= 57))) {
            e--;
            continue;
        }
        if(toupper(s[i]) != toupper(s[e]))
            return false;
        i++;e--;
    }
    return true;
    return 0;
}