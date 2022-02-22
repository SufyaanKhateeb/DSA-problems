#include <iostream>
#include <vector>

using namespace std;

int peak(int arr[], int n) {
    int s = 0, e = n - 1, mid;
    while (s < e) {
        mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int main() {
    int arr[] = { 3, 4, 5, 6 ,2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak element at index: " << peak(arr, size) << endl;

    return 0;
}