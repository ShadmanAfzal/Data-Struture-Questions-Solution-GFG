#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class Queue
{
    public:
    Node* front,*rear;
};

Queue* CreateQueue()
{
    Queue* queue = new Queue();
    queue->front = queue->rear = NULL;
    return queue;
}

void push(Queue* q,int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    if(q->rear==NULL)
    {
        q->front=q->rear = newNode;
        return; 
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int pop(Queue* q)
{
    if(q->front==NULL)
        return INT_MIN;
    q->front = NULL;
}

void pop()