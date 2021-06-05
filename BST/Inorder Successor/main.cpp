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

Node* findInorderSuccessor(Node* root,Node* toFind)
{   
    if(root==NULL)
        return NULL;
    if(toFind->right != NULL)
    {
        Node* curr = toFind->right;
        while(curr->left!=NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    Node* succ = NULL;
    while(root!=NULL)
    {
        if(toFind->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if(toFind->data > root->data)
        {
            root = root->right;
        }
        else break;
    }
    return succ;

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
    cout<<findInorderSuccessor(root,root->left->right->left)->data<<" ";
}