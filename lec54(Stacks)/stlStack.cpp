#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
    } cout << endl;

    if(s.empty())
        cout << "Stack is Empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    return 0;
}