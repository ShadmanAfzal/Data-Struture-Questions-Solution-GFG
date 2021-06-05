#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void generateDoublyLinkedList(Node *head)
{
    Node *previous = null;
    cout << "Enter no. of nodes you want to generate" << endl;
    int size;
    cin >> size;
    cout << "Enter elements into the list" << endl;
    while (size--)
    {
        int data;
        cin >> data;
        if (head->data == null)
        {
            head->data = data;
            head->prev = null;
            head->next = null;
            previous = head;
        }
        else
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = null;
            newNode->prev = previous;
            previous->next = newNode;
            previous = newNode;
        }
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node *insertInBegin(Node *head,int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    head->prev = newNode;
    newNode->next = head;
    return newNode;
}

Node *insertAtLast(Node *head,int data)
{
    Node *newNode = new Node();
    Node *temp = head;
    newNode->data = data;
    while(temp->next!=null)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

Node *reverseList(Node *head)
{
    Node *current = head;
    Node *ptr1 = head;
    Node *ptr2 = ptr1->next;

    ptr1->next= null;
    ptr1->prev = ptr2;

    while(ptr2!=null)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    return ptr1;
}

int main()
{
    Node *head = new Node();
    generateDoublyLinkedList(head);
    head = insertInBegin(head,0);
    insertAtLast(head,99);
    printList(head);
    head = reverseList(head);
    printList(head);
}