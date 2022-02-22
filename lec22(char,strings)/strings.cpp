#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getlength(char arr[]) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char name[20];
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Your name is " << name << endl;
    cout << "length: " << getlength(name) << endl;

    return 0;
}