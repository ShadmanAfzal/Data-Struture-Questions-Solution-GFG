#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    int capacity;
public:
    int *HeapArr; 
    int heap_size;
    MinHeap(int capacity);

    void heapify(int);

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (i*2 + 1);
    }

    int right(int i){
        return (i*2 + 2);
    }

    int extractMin();

    int getMin(){
        return HeapArr[0];
    }

    void insert(int ele);
};

MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    this->HeapArr = new int[capacity];
    this->heap_size = 0;
}

void MinHeap::insert(int k){
    if(heap_size==capacity)
    {
        cout<<"Stackoverflow";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    HeapArr[i] = k;

    while(i != 0 and HeapArr[parent(i)] > HeapArr[i]){
        swap(HeapArr[parent(i)], HeapArr[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(heap_size <= 0)
    {
        return -1;
    }
    if(heap_size==1){
        heap_size--;
        return HeapArr[0];
    }

    int root = HeapArr[0];
    HeapArr[0] = HeapArr[heap_size - 1];
    heap_size--;
    heapify(0);

    return root;
}

void MinHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size and HeapArr[l] < HeapArr[i])
        smallest = l;

    if(r < heap_size and HeapArr[r] < HeapArr[smallest])
        smallest = r;

    if(smallest != i){
        swap(HeapArr[i],HeapArr[smallest]);
        heapify(smallest);
    }
}

int main()
{
    MinHeap minHeap = MinHeap(11);
    minHeap.insert(9);
    minHeap.insert(1);
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(7);
    minHeap.insert(2);

    while(minHeap.heap_size){
        cout<<minHeap.extractMin()<<" ";
    }
}