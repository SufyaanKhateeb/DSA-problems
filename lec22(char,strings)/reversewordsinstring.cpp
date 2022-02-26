#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverse(vector<char>& s, int i, int j) {
    while (i < j) {
        swap(s[i++], s[j--]);
    }
}

void reversesentence(vector<char>& s) {
    int i = 0;
    int j;
    for (j = 0; j < s.size(); j++)
    {
        if (s[j] == ' ') {
            reverse(s, i, j - 1);
            i = j + 1;
        }
    }
    reverse(s, i,j-1);
    reverse(s, 0, s.size() - 1);

}

void printarr(vector<char>& s, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    } cout << endl;
}

int main() {
    vector<char> s = { 't','h','e',' ','m','a','n',' ','i','s',' ','n','i','c','e' };
    printarr(s, s.size());
    reversesentence(s);
    printarr(s, s.size());

    return 0;
}