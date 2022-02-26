#include <iostream>

using namespace std;

bool linearsearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return true;
    }
    return false;
}

int main() {
    int size, key;
    cout << "Enter size: ";
    cin >> size;
    cout << "Key element to find: ";
    cin >> key;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6 };
    if (linearsearch(arr, size, key))
        cout << "Element present." << endl;
    else
        cout << "Element does not exist." << endl;

    return 0;
}