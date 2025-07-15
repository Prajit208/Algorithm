#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
int main() {
    int N;
    cout << "Enter the number of random integers to sort: ";
    cin >> N;
    vector<int> arr(N);
    srand(time(0)); // Seed random number generator

    cout << "Generating " << N << " random integers..." << endl;
    for (int i = 0; i < N; i++)
        arr[i] = rand();
    // Measure runtime
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Array sorted using Merge Sort." << endl;
    cout << "Time taken: " << duration.count() << " milliseconds." << endl;
    cout << "Sorted elements:" << endl;
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    return 0;
}
