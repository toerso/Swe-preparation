#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    int heap_size = 0;

public:
    MaxHeap(vector<int>::iterator start, vector<int>::iterator end) {
        while (start != end) {
            this->heap.emplace_back(*start);
            start++;
        }

        this->heap_size = this->heap.size();
        build_max_heap();
    }

public:
    void push(int value) {
        this->heap.emplace_back(value);
        this->heap_size += 1;
        build_max_heap();
    }

    int top() {
        return this->heap[0];
    }

    void pop() {
        swap(this->heap[0], this->heap[this->heap_size - 1]);
        this->heap_size -= 1;
        this->heap.pop_back();
        this->max_heapify(0);
    }

private:
    void max_heapify(int i) {
        int largest;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < this->heap_size and this->heap[left] > this->heap[i]) {
            largest = left;
        }else {
            largest = i;
        }

        if (right < this->heap_size and this->heap[right] > this->heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(this->heap[i], this->heap[largest]);
            max_heapify(largest);
        }
    }

    void build_max_heap() {
        for (int i = this->heap_size / 2; i >= 0; i--) {
            max_heapify(i);
        }
    }
};

int main() {
    vector<int> heap = {1, 2, 3, 4, 5, 6, 8};
    MaxHeap max_heap(heap.begin(), heap.end());
    max_heap.push(20);
    
    cout << max_heap.top() << "\n";

    max_heap.pop();

    cout << max_heap.top() << "\n";

    return 0;
}