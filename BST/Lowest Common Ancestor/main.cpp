#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* findLCA(Node* root,int d1, int d2)
{
    if(root==NULL)
        return NULL;
    if(root->data > d1 && root->data > d2)
        return findLCA(root->left,d1,d2);
    else if(root->data < d1 && root->data < d2)
        return findLCA(root->right,d1,d2);
    else return root;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout<<findLCA(root,10,22)->data<<endl;
}