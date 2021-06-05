#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int key)
    {
        this->data = key;
        this->next = NULL;
    }
};

Node* buildLinkedList(int arr[],int size)
{
    Node* prev = NULL;
    Node* head = NULL;
    for(int i=0;i<size;i++)
    {
        if(head==NULL)
        {
            head = new Node(arr[i]);
            head->next =  NULL;
            prev = head;
        }
        else {
            Node* newNode = new Node(arr[i]);
            newNode->next = NULL;
            prev->next = newNode;
            prev = newNode;
        }
        
    }
    return head;
}


void printList(Node* root)
{
    Node* temp = root;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void generateHelper(Node* list,map<int,bool>  &helper)
{   
    Node* temp = list;
    while(temp)
    {
        helper[temp->data] = true;
        temp = temp->next;
    }
}

void findInterection(map<int,bool> helper,Node* list,set<int> &listIntersection)
{
    Node* temp = list;
    while(temp)
    {
        if(helper.count(temp->data)==1)
        {
            listIntersection.insert(temp->data);
        }
        temp = temp->next;
    }
}

int main()
{
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {2,10,5,4,2};
    int n = sizeof(arr1)/sizeof(*arr1);
    int m = sizeof(arr2)/sizeof(*arr2);
    Node* list1 = buildLinkedList(arr1,n);
    Node* list2 = buildLinkedList(arr2,m);
    map<int,bool> helper;
    generateHelper(list1, helper);
    set<int> listUnion;
    set<int> listIntersection;
    findInterection(helper,list2,listIntersection);
    for(set<int>::iterator i = listIntersection.begin() ; i != listIntersection.end(); i++)
        cout<<*i<<" ";

}