#include <iostream>

using namespace std;

int firstoccurrance(int arr[], int n, int key) {
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int lastoccurrance(int arr[], int n, int key) {
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = { 4, 10 ,35 ,100, 100, 100, 100, 250 };
    cout << "First occurerance index: " << firstoccurrance(arr, 8, 100) << endl;
    cout << "Last occurerance index: " << lastoccurrance(arr, 8, 100) << endl;
    return 0;
}