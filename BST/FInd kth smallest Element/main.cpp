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

Node* findKthSmallestNode(Node* root,int &k)
{
    if(root==NULL) return NULL;
    Node* left = findKthSmallestNode(root->left,k);
    if(left!=NULL) return left;
    k--;
    if(k==0)
        return root;
    return findKthSmallestNode(root->right,k);
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
    int k = 3;
    cout<<findKthSmallestNode(root,k)->data;
    cout<<"\nfinished"<<endl;
}