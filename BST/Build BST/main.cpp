#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;
    Node(int key)
    {
        this->data = key;
        this->left = this->right = NULL;
    }
};

Node* buildTree(Node* root,int data)
{
    if(root==NULL)
        return new Node(data);
    if(root->data > data)
        root->left = buildTree(root->left,data);
    else if(root->data < data)
        root->right = buildTree(root->right,data);
    return root;
}

Node* deleteNode(Node* root,int data)
{
    if(root==NULL)
        return root;
    if(root->data == data)
    {
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left && root->right)
        {
            Node* current = root->right;
            while(!current && current->left!=NULL)
                current = current->left;
            root->data = current->data;
            root->right = deleteNode(root->right,current->data);
        }
    }
    else if(root->data < data)
        root->right = deleteNode(root->right,data);
    else if(root->data > data)
        root->left = deleteNode(root->left,data);
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr!=NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout<<curr->data<<" ";
        s.pop();
        curr = curr->right;
    }   
}

// void inorder(Node* root)
// {
//     if(!root)
//         return;
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

int main()
{
    /*
            10
           /  |
          5   12
        /      \ 
       2        24
       \       / \
       4      23  64 
    */    
    int arr[] = {10,5,2,4,12,24,23,64};
    int n = sizeof(arr)/sizeof(*arr);
    Node* root = new Node(arr[0]);
    for(int i=1;i<n;i++)
        buildTree(root,arr[i]);
    root = deleteNode(root,5);
    inorder(root);
}