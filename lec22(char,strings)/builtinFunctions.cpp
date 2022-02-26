#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    char name1[30] = "sufyaan";
    char name2[30] = "khateeb";
    // cin >> name;
    cout << name1 << endl;
    cout << name2 << endl;
    cout << "length: " << strlen(name1) << endl;
    cout << "Output of strcmp() is " << strcmp(name1, name2) << endl;
    cout << "If not equal than strcmp() returns 1 else 0 (if equal)." << endl;
    cout << "To copy string we use strcpy(dest, src)" << endl;
    char name3[30];
    strcpy(name3, name1);
    cout << name3 << endl;
    // string name;

    return 0;
}