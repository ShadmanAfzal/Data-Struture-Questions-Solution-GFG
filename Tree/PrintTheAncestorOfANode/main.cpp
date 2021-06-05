#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    Node(int data)
    {
        this->key = data;
        this->left = this->right = null;
    }
};

void printInorder(Node *root)
{
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->key<<" ";
    printInorder(root->right);
}

bool printAncestor(Node* root,int node)
{
    if(!root)
        return false;
    if(root->key==node)
        return true;
    
    if(printAncestor(root->left,node) || printAncestor(root->right,node))
    {
        cout<<root->key<<" ";
        return true;
    }
    else
        return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(6);
    root->left->left->left->right = new Node(7);
    printAncestor(root,2);
    cout<<"return 0"<<endl;
    // printInorder(root);
}