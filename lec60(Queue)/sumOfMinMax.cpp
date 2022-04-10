// Sum of minimum and maximum elements of all subarrays of size k.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMinMaxSum(int arr[], int n, int k) {
    int sum = 0;
    deque<int> min;
    deque<int> max;
    for (int i = 0; i < n; i++) {
        // removing the front index if it is not in k sized window
        if (!min.empty() && min.back() == i - k) min.pop_front();
        if (!max.empty() && max.back() == i - k) max.pop_front();

        // removing the elements from back if it is greater than the index element
        while (!min.empty() && arr[min.back()] > arr[i]) min.pop_back();
        // removing the elements from back if it is greater than the index element
        while (!max.empty() && arr[max.back()] < arr[i]) max.pop_back();

        // adding the index to the back of queues
        min.push_back(i);
        max.push_back(i);

        // adding to the sum the front of both the queues if i >= k
        if (i >= k - 1) sum += arr[min.front()] + arr[max.front()];
    }
    return sum;
}

int main() {
    int arr[] = { 2, 5, -1, 7, -3, -1, -2 };
    int n = sizeof(arr) / sizeof(int);
    int k = 4;
    cout << findMinMaxSum(arr, n, k) << endl;

    return 0;
}