#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key) {
    int s = 0, e = n - 1, mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Binary Search for 3: " << binarySearch(arr, size, 3) << endl;

    return 0;
}