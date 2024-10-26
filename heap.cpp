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

    void maxHeapify(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    Heap() {}

    void buildMaxHeap() {
        int startIndex = (heap.size() / 2) - 1;
        for (int i = startIndex; i >= 0; --i) {
            maxHeapify(i);
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
        maxHeapify(0);
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
        maxHeapify(minIndex);
        return minValue;
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap maxHeap;
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
    cout << "extract min: " << maxHeap.extractMin() << endl;
    maxHeap.printHeap();

    cout << "extract max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();

    return 0;
}
