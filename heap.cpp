#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void maxHeapify(int index, int heapSize) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heapSize && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(largest, heapSize);
        }
    }

public:
    Heap() {}

    void buildMaxHeap() {
        int startIndex = (heap.size() / 2) - 1;
        for (int i = startIndex; i >= 0; --i) {
            maxHeapify(i, heap.size());
        }
    }

    void insert(int key) {
        heap.push_back(key);
        buildMaxHeap(); 
    }

    int extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0, heap.size());
        return root;
    }

    int extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i] < heap[minIndex]) {
                minIndex = i;
            }
        }

        int minValue = heap[minIndex];
        heap[minIndex] = heap.back();
        heap.pop_back();
        maxHeapify(minIndex, heap.size());
        return minValue;
    }

    void heapSort() {
        buildMaxHeap();
        for (int i = heap.size() - 1; i >= 1; i--) {
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }

    
    void priorityQueue() {
        insert(16);
        insert(14);
        insert(10);
        insert(8);
        insert(7);
        insert(9);
        insert(3);
        insert(2);
        insert(4);
        insert(1);

        cout << "Priority Queue after inserts: ";
        printHeap();

        cout << "Extracted max: " << extractMax() << endl;
        printHeap();

        cout << "Extracted min: " << extractMin() << endl;
        printHeap();

        cout << "Extracted max again: " << extractMax() << endl;
        printHeap();
    }
};

int main() {
    Heap maxHeap;
    maxHeap.priorityQueue(); 

    maxHeap.heapSort();
    cout << "Sorted array: ";
    maxHeap.printHeap();

    return 0;
}
