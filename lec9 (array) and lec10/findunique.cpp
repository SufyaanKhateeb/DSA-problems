#include <iostream>

using namespace std;

int findUnique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j])
                flag = 1;
        }
        if (!flag)
            return arr[i];
    }
    return -1;
}

int main() {
    int arr[] = { 1, 1, 2, 2, 3, 5, 5 };
    int ans = findUnique(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Ans: " << ans << endl;
    return 0;
}