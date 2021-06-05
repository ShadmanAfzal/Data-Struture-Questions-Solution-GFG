#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *arr;
};

Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = new int[queue->capacity];
    return queue;
}

bool isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue,int item)
{
    if(isFull(queue))
        return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size+1;
    // cout<<"Item enqueued "<<endl;
}

int dequeue(Queue* queue)
{
    if(isFull(queue))
        return INT_MAX;
    int item = queue->arr[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size = queue->size-1;
    return item;
    // cout<<"Item dequeued "<<endl;
}

int front(Queue* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    return item;
}

int rear(Queue* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->rear];
    return item;
}

void display(Queue* queue)
{
    Queue* temp = queue;
    while (!isEmpty(temp))
    {
        cout<<dequeue(temp)<<" ";
        // temp->
    }
    cout<<endl;
    
}

int main()
{
    Queue* queue = createQueue(100000);
    for(int i=0;i<5;i++)
        enqueue(queue,i);
    display(queue);
}