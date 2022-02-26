#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;

}

int main() {
    int arr[] = { 2, 4, 1, 0, 0 ,14 , 0, 29 };
    int n = 8;
    int snowball = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            snowball++;
        else if(snowball>0)
            swap(arr[i], arr[i - snowball]);
    }
    
    printarr(arr, n);

    return 0;
}