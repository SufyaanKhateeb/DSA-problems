#include <iostream>

using namespace std;

void reversearr(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    while (s < e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
    // for (int i = 0; i < (size) / 2; i++)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[size - 1 - i];
    //     arr[size - 1 - i] = temp;
    // }
}

void printarr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7 };
    reversearr(arr, sizeof(arr) / sizeof(int));
    printarr(arr, sizeof(arr) / sizeof(int));
    return 0;
}