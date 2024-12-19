#include <iostream>
using namespace std;

// Max-Heapify function
void MaxHeapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);    // Recursively heapify the affected subtree
    }
}

// Build-Max-Heap function
void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);
}

// Heapsort function
void HeapSort(int arr[], int n) {
    // Step 1: Build a max heap
    BuildMaxHeap(arr, n);

    // Step 2: Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);       // Move current root to end
        MaxHeapify(arr, i, 0);      // Call MaxHeapify on the reduced heap
    }
}

// Utility function to print an array
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    PrintArray(arr, n);

    HeapSort(arr, n);

    cout << "Sorted array: ";
    PrintArray(arr, n);

    return 0;
}
