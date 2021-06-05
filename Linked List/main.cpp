#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void makeList(Node *head)
{
    int size;
    cout << "Enter the size of Linked List" << endl;
    cin >> size;
    cout << "Enter element" << endl;
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        Node *prev;
        if (head->data == NULL)
        {
            head->data = data;
            head->next = NULL;
            prev = head;
        }
        else
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            prev->next = temp;
            prev = temp;
        }
    }
}

Node *updateHead(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    return temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addNodeBeforeAElement(Node *head, int data, int before)
{
    Node *newNode = new Node();
    Node *ptr = head;
    Node *preptr = NULL;
    while (ptr->data != before)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->data = data;
    newNode->next = ptr;
}

void addNodeAfterAElement(Node *head, int data, int after)
{
    Node *newNode = new Node();
    newNode->data = data;
    Node *ptr = head;
    while (ptr->data != after)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void AddToEnd(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    Node *ptr = head;
    while (ptr->next != null)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void deleteAKey(Node *head, int key)
{
    Node *ptr = head;
    Node *preptr = null;
    while (ptr->data != key)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

Node *deleteHead(Node *head)
{
    return head->next;
}

void DeleteAtPos(Node *head, int pos)
{
    Node *ptr = head;
    Node *preptr = null;
    for (int i = 0; i < pos && ptr->next != null; i++)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    cout << "Key deleted successfully" << endl;
}

int lenghtUsingIteration(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != null)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

int findLenghtUsingRecussion(Node *head)
{
    if (head == null)
        return 0;
    return 1 + findLenghtUsingRecussion(head->next);
}

Node *reversedLinkedList(Node *head)
{
    Node *prev = null;
    Node *next = null;
    Node *current = head;
    while (current != null)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void swapNode(Node *head, int key1, int key2)
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    Node *pre1 = null;
    Node *pre2 = null;
    while (ptr1->data != key1)
    {
        ptr1 = (ptr1)->next;
    }

    while (ptr2->data != key2)
    {
        ptr2 = ptr2->next;
    }
    swap(*ptr1, *ptr2);
    swap((*ptr1->next), (*ptr2->next));
}

void sortList(Node *head)
{
    Node *ptr = head;
    while (ptr->next != null)
    {
        Node *ptr1 = ptr->next;
        while (ptr1 != null)
        {
            if (ptr->data > ptr1->data)
            {
                int temp = ptr->data;
                ptr->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

Node *mergeTwoList(Node *head1, Node *head2)
{
    Node *endNode = head1;
    while (endNode->next != null)
    {
        endNode = endNode->next;
    }
    endNode->next = head2;
    sortList(head1);
    return head1;
}



int main()
{
    Node *head1 = new Node();
    Node *head2 = new Node();
    makeList(head1);
    cout << "Linked List 1 :" << endl;
    printList(head1);
    makeList(head2);
    cout<<"Linked List 2 :"<<endl;
    printList(head2);
    Node *newHead = mergeTwoList(head1,head2);
    cout<<"Combine :"<<endl;
    printList(head1);
    AddToEnd(newHead,0);
    sortList(newHead);
    cout<<"After adding New node"<<endl;
    printList(newHead);
    cout << "EOD" << endl;
}