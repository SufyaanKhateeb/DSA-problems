// #include <iostream>

// using namespace std;

// int findpivot(int arr[], int n) {
//     int s = 0;
//     int e = n - 1;
//     int mid;
//     while (s < e) {
//         mid = s + (e - s) / 2;
//         if (arr[mid] >= arr[0])
//             s = mid + 1;
//         else
//             e = mid;
//     }
//     return e;
// }

// int binarySearch(int arr[], int target, int s, int e) {
//     int mid;
//     while (s <= e) {
//         mid = s + (e - s) / 2;
//         if (arr[mid] == target)
//             return mid;
//         else if (arr[mid] < target)
//             s = mid + 1;
//         else
//             e = mid - 1;
//     }
//     return -1;
// }

// int main() {
//     int arr[] = { 3,1 };
//     int target = 1;
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int pivot = findpivot(arr, size);
//     if (pivot == size - 1)
//         cout << binarySearch(arr, target, 0, size - 1) << endl;
//     if (arr[pivot] == target)
//         cout << pivot << endl;
//     else if (arr[0] <= target)
//         cout << binarySearch(arr, target, 0, pivot - 1) << endl;
//     else
//         cout << binarySearch(arr, target, pivot + 1, size - 1) << endl;

//     return 0;
// }

//approach no. 2
#include <iostream>

using namespace std;

int findtarget(int arr[], int target, int size) {
    int s = 0;
    int e = size - 1;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        //left side sorted
        if (arr[s] <= arr[mid]) {
            if (arr[s] <= target && arr[mid] >= target) {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        else {            //right side sorted
            if (arr[mid] <= target && arr[e] >= target) {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 4,5,6,7,0,1,2 };
    int target = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findtarget(arr, target, size) << endl;
    return 0;
}