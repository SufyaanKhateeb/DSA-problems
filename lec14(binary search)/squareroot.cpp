#include <iostream>

using namespace std;

int sroot(int num) {
    int s = 0;
    int e = num;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (mid * mid == num)
            return mid;
        else if (mid * mid > num)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return e;
}

double precision(int n, int precision, int tempsol) {
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = tempsol; j < n / j; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int num = 8;
    int tempsol = sroot(num);
    cout << "Ans: " << sroot(num) << endl;
    cout << "Ans precise: " << precision(num, 3, tempsol) << endl;

    return 0;
}