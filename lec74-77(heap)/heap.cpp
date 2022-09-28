#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteMax() {
        if (size == 0) {
            cout << "The heap is empty." << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size) {
            int largest = i;
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[largest] < arr[leftIndex])
                largest = leftIndex;
            if (rightIndex < size && arr[largest] < arr[rightIndex])
                largest = rightIndex;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
                return;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }
};


void maxheapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    if (leftIndex <= n && arr[largest] < arr[leftIndex])
        largest = leftIndex;
    if (rightIndex <= n && arr[largest] < arr[rightIndex])
        largest = rightIndex;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void minheapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    if (leftIndex <= n && arr[smallest] > arr[leftIndex])
        smallest = leftIndex;
    if (rightIndex <= n && arr[smallest] > arr[rightIndex])
        smallest = rightIndex;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void heapSort(vector<int>& arr, int n) {
    int temp = n;
    while (temp > 1) {
        swap(arr[1], arr[temp]);
        temp--;

        if (temp == 1)
            return;
        maxheapify(arr, temp, 1);
    }
}

int main() {

    Heap h;
    h.insert(70);
    h.insert(50);
    h.insert(55);
    h.insert(30);
    h.insert(20);
    h.insert(10);

    h.deleteMax();
    // h.deleteMax();

    h.print();

    vector<int> arr = { -1 , 54, 53, 55, 52, 50 };
    int n = arr.size() - 1;

    // creating a max heap
    for (int i = n / 2; i >= 1; i--) {
        maxheapify(arr, n, i);
    }

    cout << "Printing the Max Heap: " << endl;
    for (auto it : arr)
        cout << it << " ";

    // Sorting the heap using heap sort
    heapSort(arr, n);

    cout << endl << "Printing the sorted heap: " << endl;
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    
    // using priority queue which is same logic as heap
    // by default it is a maxheap
    priority_queue<int> maxHeap;
    maxHeap.push(54);
    maxHeap.push(34);
    maxHeap.push(94);
    maxHeap.push(40);

    cout << "Top: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Top: " << maxHeap.top() << endl;

    // minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(54);
    minHeap.push(34);
    minHeap.push(94);
    minHeap.push(40);

    cout << "Top: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top: " << minHeap.top() << endl;

    return 0;
}