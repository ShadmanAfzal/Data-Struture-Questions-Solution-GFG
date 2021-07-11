#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int capacity;
public:
    int *harr;
    int size;

    int parent(int i){ 
        return (i - 1)/2; 
    }
    int left(int i) { return (i*2 + 1) ; }
    int right(int i) { return (i*2 + 2); }

    MaxHeap(int capacity);
    void insert(int k);
    void heapify(int i);
    void heapifyUp(int i);
    int extractMax();
};

MaxHeap::MaxHeap(int capacity)
{
    this->capacity = capacity;
    this->harr = new int[capacity];
    this->size = 0;
}

void MaxHeap::insert(int k)
{
    if (size == capacity)
    {
        cout << "Stackoverflow" << endl;
        return;
    }
    size++;
    int i = size - 1;
    harr[i] = k;

    heapifyUp(i);
}

int MaxHeap::extractMax(){
    if(size <= 0){
        return -1;
    }

    if(size==1){
        size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[size - 1];
    size--;

    heapify(0);
    
    return root;
}

void MaxHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < size and harr[l] > harr[i])
        largest = l;
    if(r < size and harr[r] > harr[largest])
        largest = r;

    if(largest != i){
        swap(harr[largest],harr[i]);
        heapify(largest);
    }
}

void MaxHeap::heapifyUp(int i){
    if(i and harr[parent(i)] < harr[i]){
        swap(harr[parent(i)], harr[i]);
        heapifyUp(i);
    }
}

int main()
{
    MaxHeap maxHeap = MaxHeap(11);
    maxHeap.insert(7);
    maxHeap.insert(9);
    maxHeap.insert(1);
    maxHeap.insert(3);
    maxHeap.insert(5);
    maxHeap.insert(2);

    while(maxHeap.size){
        cout<<maxHeap.extractMax()<<" ";
    }
}