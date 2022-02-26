(pivot == size - 1)
        cout << binarySearch(arr, target, 0, size - 1) << endl;
    if (arr[pivot] == target)
        cout << pivot << endl;
    else if (arr[0] <= target)
        cout << binarySearch(arr, target, 0, pivot - 1) << endl;
    else
       