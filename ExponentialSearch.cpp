#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

// Binary Search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential Search function
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 999);

    // Fill array with random numbers
    for (int i = 0; i < n; ++i)
        arr[i] = dis(gen);

    // Display unsorted array
    cout << "\nUnsorted Array:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    // Sort the array
    sort(arr, arr + n);

    // Display sorted array
    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    int target;
    cout << "\nEnter the number to search: ";
    cin >> target;

    // Measure runtime
    auto start = high_resolution_clock::now();
    int index = exponentialSearch(arr, n, target);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nSearch Time: " << duration.count() << " microseconds\n";

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found.\n";

    delete[] arr; // Clean up dynamic array
    return 0;
}
