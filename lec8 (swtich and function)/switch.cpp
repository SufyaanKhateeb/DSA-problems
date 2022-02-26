#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int rupees = 100;
    int count100 = 0, count50 = 0, count20 = 0, count1 = 0;
    while (true) {
        switch (rupees) {
        case 100: {
            if (n < 100) {
                rupees = 50;
                break;
            }
            count100 = n / 100;
            n -= (count100 * 100);
            break;
        }
        case 50: {
            if (n < 50) {
                rupees = 20;
                break;
            }
            count50 = n / 50;
            n -= (count50 * 50);
            break;
        }
        case 20: {
            if (n < 20) {
                rupees = 1;
                break;
            }
            count20 = n / 20;
            n -= (count20 * 20);
            break;
        }
        case 1: {
            if (n < 1) {
                rupees = 0;
                break;
            }
            count1 = n / 1;
            n -= (count1 * 1);
            break;
        }
        default: {
            cout << "100 - " << count100 << endl;
            cout << "50 - " << count50 << endl;
            cout << "20 - " << count20 << endl;
            cout << "1 - " << count1 << endl;
            exit(0);
        }
        }
    }

    return 0;
}