#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isRobotBounded(string instructions) {
    int x = 0, y = 0, i = 0;
    vector<vector<int>> d = { {0, 1}, {1, 0}, {0, -1}, { -1, 0} };
    for (char& ins : instructions)
        if (ins == 'R') {
            i = (i + 1) % 4;
            cout << i << endl;
        }
        else if (ins == 'L') {
            i = (i + 3) % 4;
            cout << i << endl;
        }
        else {
            x += d[i][0], y += d[i][1];
            cout << "x: " << x << " y: " << y << endl;
        }
    return x == 0 && y == 0 || i > 0;
}

int main() {
    string dir = "GGLLGG";
    cout << isRobotBounded(dir);

    return 0;
}