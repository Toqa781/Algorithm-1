#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

template<typename T>
class Heap {
protected:
    vector<T> heap;

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

    void insert(const T& key) {
        heap.push_back(key);
        int index = heap.size() - 1;

        while (index != 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    T extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }

        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0, heap.size());

        return root;
    }
    T extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }


        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i] < heap[minIndex]) {
                minIndex = i;
            }
        }

        T minValue = heap[minIndex];
        heap[minIndex] = heap.back();
        heap.pop_back();
        maxHeapify(minIndex, heap.size()); 
        return minValue;
    }
    void heapSort() {
        buildMaxHeap();
        int heapSize = heap.size();
        for (int i = heapSize - 1; i >= 1; --i) {
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }

    void printHeap() const {
        for (const auto& val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class PriorityQueue : public Heap<pair<int, int>> {
public:
    // Insert element with priority
    void insert(int priority, int data) {
        Heap<pair<int, int>>::insert({priority, data});
    }


    pair<int, int> extractMax() {
        return Heap<pair<int, int>>::extractMax();
    }


    pair<int, int> extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i].first < heap[minIndex].first) {
                minIndex = i;
            }
        }

        pair<int, int> minValue = heap[minIndex];
        heap[minIndex] = heap.back();
        heap.pop_back();
        // Rebuild max heap to maintain properties after removal
        for (int i = (minIndex - 1) / 2; i >= 0; --i) {
            maxHeapify(i, heap.size());
        }
        for (int i = minIndex; i < heap.size(); ) {
            maxHeapify(i, heap.size());
            i = leftChild(i);
        }

        return minValue;
    }


    void printHeap() const {
        for (const auto& val : heap) {
            cout << "(" << val.first << ", " << val.second << ") ";
        }
        cout << endl;
    }
};

int main() {
    Heap<int> maxHeap;
    maxHeap.insert(16);
    maxHeap.insert(14);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(7);
    maxHeap.insert(9);
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(4);
    maxHeap.insert(1);

    maxHeap.printHeap();

    cout << "extract max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();

    cout << "extract max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();
    cout << "Extract min: " << maxHeap.extractMin() << endl;
    maxHeap.printHeap();
    maxHeap.heapSort();
    cout << "Sorted array: ";
    maxHeap.printHeap();

    PriorityQueue pq;


    pq.insert(10, 16);
    pq.insert(9, 14);
    pq.insert(8, 10);
    pq.insert(7, 8);
    pq.insert(6, 7);
    pq.insert(5, 9);
    pq.insert(4, 3);
    pq.insert(3, 2);
    pq.insert(2, 4);
    pq.insert(1, 1);

    cout << "Priority Queue (Heap): ";
    pq.printHeap();


    cout << "Extract max (highest priority): ";
    auto maxElement = pq.extractMax();
    cout << "(" << maxElement.first << ", " << maxElement.second << ")" << endl;
    pq.printHeap();
    cout << "Extract min (lowest priority): ";
    auto minElement = pq.extractMin();
    cout << "(" << minElement.first << ", " << minElement.second << ")" << endl;
    pq.printHeap();

    cout << "Sorted by priority (Heap Sort): ";
    pq.heapSort();
    pq.printHeap();

    return 0;
}
