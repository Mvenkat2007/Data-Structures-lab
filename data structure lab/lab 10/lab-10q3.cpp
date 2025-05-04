#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to heapify the heap
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Insert an element into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        // Move the new element to its correct position
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Delete the root element (maximum) from the heap
    void deleteRoot() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    // Display the elements of the heap
    void display() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Search for an element in the heap
    bool search(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value)
                return true;
        }
        return false;
    }

    // Perform heap sort (sorts the heap in descending order)
    void heapSort() {
        vector<int> sortedHeap = heap;
        int n = sortedHeap.size();

        // Build the heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(sortedHeap, i, n);
        }

        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            swap(sortedHeap[0], sortedHeap[i]);
            heapifyDown(sortedHeap, 0, i);
        }

        cout << "Sorted elements (Descending Order): ";
        for (int i = 0; i < n; i++) {
            cout << sortedHeap[i] << " ";
        }
        cout << endl;
    }

private:
    // Helper function to heapify a specific part of the array
    void heapifyDown(vector<int>& arr, int index, int size) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(arr, largest, size);
        }
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\nPriority Queue Menu (Max Heap):\n";
        cout << "1. Insert\n";
        cout << "2. Delete (Root)\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteRoot();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value)) {
                    cout << "Value found in the heap." << endl;
                } else {
                    cout << "Value not found in the heap." << endl;
                }
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
// time complexity

//Insert: O(log n)

// Delete (Root): O(log n)

// Display: O(n)

// Search: O(n)

// Heap Sort: O(n log n)