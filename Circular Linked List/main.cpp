#include <bits/stdc++.h>
#define null NULL
using namespace std;

class CircularList
{
public:
    int data;
    CircularList *next;
};

void CreateList(CircularList *head)
{
    int size;
    cout << "Enter the size of List" << endl;
    cin >> size;
    CircularList *prev = null;
    cout << "Enter Elements into the List" << endl;
    while (size--)
    {
        int element;
        cin >> element;
        if (head->data == null)
        {
            head->data = element;
            head->next = null;
            prev = head;
        }
        else
        {
            CircularList *newNode = new CircularList();
            newNode->data  = element;
            newNode->next = null;
            prev->next = newNode;
            prev = newNode;
        }
    }
    prev->next = head;
}

void printList(CircularList *head)
{
    CircularList *ptr = head;
    while(ptr!=null)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
        if(ptr->data==head->data)
        {
            cout<<"\nCircular List found"<<endl;
            break;
        }
    }
    cout<<endl;
}

CircularList *insertHeadList(CircularList *head,int data)
{
    CircularList *newNode = new CircularList();
    newNode->data = data;
    newNode->next = head;
    CircularList *ptr = head->next;
    CircularList *pre = null;
    while(ptr->data!=head->data)
    {
        pre = ptr;
        ptr = ptr->next;
    }
    pre->next = newNode;
    return newNode;
}


void insertAtLast(CircularList *head,int data)
{
    CircularList *newNode = new CircularList();
    newNode->data = data;
    CircularList *temp = head;
    while(temp->next->data!=head->data)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void sortList(CircularList *head)
{
    CircularList *node = head->next;
    while(node->data!=head->data)
    {
        CircularList *temp = node->next;
        while(temp->data!=head->data)
        {
            if(temp->data<node->data)
            {
                int x = temp->data;
                temp->data  = node->data;
                node->data = x;
            }
            temp = temp->next;
        }
        node = node->next;

    }
}

int main()
{
    CircularList *head = new CircularList();
    CreateList(head);
    // list = insertHeadList(list,0);
    // insertAtLast(head,0);    
    sortList(head);
    printList(head);
}
