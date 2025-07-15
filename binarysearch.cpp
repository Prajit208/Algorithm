#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
//  Random Number Generator 
void generateRandomNumbers(vector<int>& data, int N, int maxVal = 100000) {
    data.clear(); 
    for (int i = 0; i < N; ++i)
        data.push_back(rand() % maxVal);  
}
// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Temporary arrays
    vector<int> L(n1), R(n2);
    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // Merge the temp arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Recursively divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the halves
        merge(arr, left, mid, right);
    }
}
//  Binary Search 
int binarySearch(const vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;  // Initialize left and right boundaries
    // Continue searching while the search range is valid
    while (l <= r) {
        // Prevents potential overflow
        int mid = l + (r - l) / 2;
        // If key is found at mid, return index
        if (arr[mid] == key) return mid;

        // If key is greater, ignore the left half
        else if (arr[mid] < key) l = mid + 1;
        // If key is smaller, ignore the right half
        else r = mid - 1;
    }
    // Element not found
    return -1;
}
int main() {
    srand(time(0));
    int N, key;
    vector<int> data;
    cout << "Enter number of random integers (N): ";
    cin >> N;
    generateRandomNumbers(data, N);
    cout << "\nOriginal Array:\n";
    for (int x : data) cout << x << " ";
    cout << endl;
    // Sort the array
    auto startSort = high_resolution_clock::now();
    mergeSort(data, 0, N - 1);
    auto endSort = high_resolution_clock::now();
    cout << "\nSorted Array (Merge Sort):\n";
    for (int x : data) cout << x << " ";
    cout << "\nTime for Merge Sort: " << duration_cast<milliseconds>(endSort -startSort).count() << " ms\n";
    // Search
    cout << "\nEnter element to search: ";
    cin >> key;
    auto startSearch = high_resolution_clock::now();
    int index = binarySearch(data, key);
    auto endSearch = high_resolution_clock::now();
    if (index != -1)
        cout << "Element found at index " << index << ".\n";
    else
        cout << "Element not found.\n";
    cout << "Time for Binary Search: "
         << duration_cast<microseconds>(endSearch - startSearch).count() << " us\n";
    return 0;
}
