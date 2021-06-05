#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = null;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeNode(Node *slow,Node *head)
{
    cout<<"here"<<endl;
    Node *temp = slow;
    if(slow==head)
    {
        while(slow->next != temp)
        {
            slow=slow->next;
        }
        slow->next = null;
    }
    else
    {
        slow = head;
        while(slow->next != temp->next)
        {
            slow = slow->next;
            temp = temp->next;
        }
        temp->next = null;   
    }    
}

void removeAndDetectLoop(Node *head)
{
    if(head==null)
        return;
    Node *slow = head,*fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        cout<<"slow "<<slow->data<<" fast "<<fast->data<<endl;
        if(slow==fast)
        {
            removeNode(slow,head);
            break;
        }
    }
}

int main()
{
    Node *head = new Node(0);
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *five = new Node(5);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = five;
    five->next = second;
    removeAndDetectLoop(head);
    print(head);
}