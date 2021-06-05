#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        Node* left,*right;
    Node(int data)
    {
        this->key = data;
        this->left = this->right = NULL;
    }
};

void findSuccessor(Node* root,int key)
{
    if(root==NULL)
        return;
    if(root->key==key)
    {
        Node* temp = root->left;
        while(temp->right!=NULL)
            temp = temp->right;
        cout<<"Predecessor->"<<temp->key<<" ";
        temp = root->right;
        while(temp->left!=NULL)
            temp = temp->left;
        cout<<"Successor->"<<temp->key<<" ";
        return;
    }
    if(root->key>key)
    {
        findSuccessor(root->left,key);
    }
    if(root->key<key)
    {
        findSuccessor(root->right,key);
    }
}

int main()
{
    Node* root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(55);
    root->right->right = new Node(70);
    findSuccessor(root,40);
}