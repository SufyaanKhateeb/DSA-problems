#include <iostream>

using namespace std;

void printarr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void sortzeroone(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    while (s < e) {
        while (arr[s] == 0 && s < e) s++;
        while (arr[e] == 1 && s < e) e--;
        if (s < e) {
            int temp = arr[e];
            arr[e] = arr[s];
            arr[s] = temp;
            s++;e--;
        }
    }
}

int main() {
    int arr[] = { 0,1,1,1,1,0,1,0,1,0 };
    sortzeroone(arr, sizeof(arr) / sizeof(arr[0]));
    printarr(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}