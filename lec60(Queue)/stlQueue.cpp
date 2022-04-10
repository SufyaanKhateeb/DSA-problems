#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout << "Front: " << q.front() << endl;
    if (q.empty())
        cout << "Empty queue." << endl;
    else
        cout << "Queue not empty." << endl;

    return 0;
}