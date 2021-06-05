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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void generateInorderList(Node* root,vector<int> &temp)
{
    if (root == NULL)
        return;
    generateInorderList(root->left,temp);
    temp.push_back(root->data);
    generateInorderList(root->right,temp);
}

void convertToBST(Node* root,int *ptr,vector<int> temp)
{
    if(!root) return;
    convertToBST(root->left,ptr,temp);
    root->data = temp[*ptr];
    (*ptr)++;
    convertToBST(root->right,ptr,temp);
}

int main()
{
    vector<int> temp;
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);
    inorder(root);
    cout<<endl;
    generateInorderList(root,temp);
    sort(temp.begin(),temp.end());
    int index = 0;
    convertToBST(root,&index,temp);
    preorder(root);
}