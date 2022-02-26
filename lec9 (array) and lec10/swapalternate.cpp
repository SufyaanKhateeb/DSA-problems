#include <iostream>

using namespace std;

void swapalternate(int arr[], int size) {
    for (int i = 0; i < size; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printarr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    swapalternate(arr, size);
    printarr(arr, size);
    return 0;
}