#include <iostream>

using namespace std;

int main() {
    int arr[100] = { 0 };
    std::fill_n(arr, 100, 1);
    for (int i = 0; i < 100; i++)
        cout << arr[i] << " ";

    return 0;
}