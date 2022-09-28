#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    int temp = 0;
    for(int i = 0; i < arr.size(); i++) {
        temp = temp | arr[i];
    }
    int x = 0;
    cout << temp << endl;
    for(int i = 31; i >= 0; i--) {
        bool lastbitfromleft = temp & (1 << i);
    }

    string s = "011";
    do {
        cout << stoi(s) << " ";
    }while (next_permutation(s.begin(),s.end()));


    return 0;
}