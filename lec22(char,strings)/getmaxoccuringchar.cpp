#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char getMaxOccuringChar(string str)
{
    int maxi = 0;
    int count[26] = { 0 };
    for (int i = 0; i < str.length(); i++) {
        count[tolower(str[i]) - 'a']++;
        maxi = max(count[tolower(str[i]) - 'a'], maxi);
    }
    for (int i = 0;i < 26;i++)
        if (count[i] == maxi) return (char)(97 + i);
    return ' ';
}

int main() {
    string str = "helloworld";
    cout << getMaxOccuringChar(str) << endl;
    return 0;
}