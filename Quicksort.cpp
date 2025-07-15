
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// User input
void takeInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }
}

int main() {
    int choice;
    cout << "Select Mode:\n";
    cout << "1. Sort your own input array\n";
    cout << "2. Measure time for QuickSort on random arrays\n";

    cin >> choice;

    if (choice == 1) {
        // User input mode
        int size;
        cout << "Enter the size of array: ";
        cin >> size;

        int arr[size];
        takeInput(arr, size);

        clock_t start = clock();
        quickSort(arr, 0, size - 1);
        clock_t end = clock();

        cout << "Sorted array:\n";
        display(arr, size);

        double microseconds = double(end - start) * 1000000.0 / CLOCKS_PER_SEC;
        cout << "\nTime Taken: " << microseconds << " μs" << endl;

    } else if (choice == 2) {
        // Benchmark mode
        int sizes[] = {1000, 5000, 10000, 50000, 100000, 500000};
        int numSizes = sizeof(sizes) / sizeof(sizes[0]);

        srand(time(0)); // Seed RNG
        cout << "\nInput Size\tTime (in microseconds)\n";
       

        for (int i = 0; i < numSizes; i++) {
            int size = sizes[i];
            int* arr = new int[size];

            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 100000;
            }

            clock_t start = clock();
            quickSort(arr, 0, size - 1);
            clock_t end = clock();

            double microseconds = double(end - start) * 1000000.0 / CLOCKS_PER_SEC;
            cout << size << "\t\t" << microseconds << "" << endl;

            delete[] arr;
        }

    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }

    return 0;
}

