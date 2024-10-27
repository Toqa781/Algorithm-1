#include <iostream>
#include <vector>


using namespace std;

class Heap {
private:
    vector<pair<int, int>> heap;

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

        if (left < heapSize && heap[left].second > heap[largest].second) {
            largest = left;
        }
        if (right < heapSize && heap[right].second > heap[largest].second) {
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

    void insert(int value, int priority) {
        heap.push_back({value, priority});
        buildMaxHeap();
    }

    pair<int, int> extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        pair<int, int> root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0, heap.size());
        return root;
    }

    pair<int, int> extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i].second < heap[minIndex].second) {
                minIndex = i;
            }
        }

        pair<int, int> minValue = heap[minIndex];
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
        for (auto& val : heap) {
            cout << "(" << val.first << ", " << val.second << ") ";
        }
        cout << endl;
    }
};
int main() {
    Heap maxHeap;
    maxHeap.insert(14, 9);
    maxHeap.insert(10, 8);
    maxHeap.insert(8, 7);
    maxHeap.insert(7, 6);
    maxHeap.insert(9, 5);
    maxHeap.insert(3, 4);
    maxHeap.insert(2, 3);
    maxHeap.insert(4, 2);
    maxHeap.insert(1, 1);

    maxHeap.printHeap();
    cout << "Extracting max (highest priority): " << endl;
    auto maxElement = maxHeap.extractMax();
    cout << "Extracted max: (" << maxElement.first << ", " << maxElement.second << ")" << endl;

    cout << "Extracting min (lowest priority): " << endl;
    auto minElement = maxHeap.extractMin();
    cout << "Extracted min: (" << minElement.first << ", " << minElement.second << ")" << endl;

    cout << "Extracting max again: " << endl;
    maxElement = maxHeap.extractMax();
    cout << "Extracted max: (" << maxElement.first << ", " << maxElement.second << ")" << endl;
    maxHeap.heapSort();
    cout << "Final sorted array by priority: ";
    maxHeap.printHeap();

    return 0;
}
