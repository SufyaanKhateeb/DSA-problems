#include <iostream>

using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    int n;
    cin >> n;
    int row = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row) {
    //         cout << row - col + 1 << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n) {
    //         char ch = 'A' + row - 1;
    //         cout << ch << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n) {
    //         char ch = 'A' + col - 1;
    //         cout << ch << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // char ch = 'A';
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n) {
    //         cout << ch << " ";
    //         col++;
    //         ch++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n) {
    //         char ch = 'A' + row + col - 2;
    //         cout << ch << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row) {
    //         char ch = 'A' + row + col - 2;
    //         cout << ch << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row) {
    //         char ch = 'A' + (n-1) - row + col;
    //         cout << ch << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     // space
    //     int space = n - row;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= row) {
    //         cout << "*";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= n - row + 1) {
    //         cout << "*";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     //space
    //     int space = row - 1;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= n - row + 1) {
    //         cout << "*";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     //space
    //     int space = row - 1;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= n - row + 1) {
    //         cout << row;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     //space
    //     int space = n - row;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= row) {
    //         cout << row;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // while (row <= n)
    // {
    //     //space
    //     int space = row - 1;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= n - row + 1) {
    //         cout << row + col - 1;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // int count = 1;
    // while (row <= n)
    // {
    //     //space
    //     int space = n - row;
    //     while (space > 0) {
    //         cout << " ";
    //         space--;
    //     }
    //     //star
    //     int col = 1;
    //     while (col <= row) {
    //         cout << count;
    //         col++;
    //         count++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    while (row <= n)
    {
        //space
        int space = n - row;
        while (space > 0) {
            cout << " ";
            space--;
        }
        //star first triangle
        int col1 = 1;
        while (col1 <= row) {
            cout << col1;
            col1++;
        }
        //star second triangle
        int col2 = row - 1;
        while (col2)
        {
            cout << col2;
            col2--;
        }
        cout << endl;
        row++;
    }
    return 0;
}