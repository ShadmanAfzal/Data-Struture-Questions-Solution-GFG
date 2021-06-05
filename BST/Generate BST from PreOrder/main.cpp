#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void printInOrder(Node* root)
{
    if(!root) return;
    cout<<root->data<<" ";
    printInOrder(root->left);
    printInOrder(root->right);
}

Node* buildTree(int pre[],int size,int *indexptr)
{
    if((*indexptr) >= size)
        return NULL;
    int index = *indexptr;
    (*indexptr)++;
    Node* root = new Node(pre[index]);
    if(root->data > pre[index+1])
    {
        root->left = buildTree(pre,size,indexptr);
    }
    else if(root->data < pre[index+1])
    {
        root->right = buildTree(pre,size,indexptr);
    }
    return root;
}

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre)/sizeof(*pre);
    int index = 0;
    Node* root = buildTree(pre,size,&index);
    printInOrder(root);
}