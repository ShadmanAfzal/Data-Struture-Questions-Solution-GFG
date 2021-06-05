#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->key = key;
        this->left = this->right = null;
    }
};

void print(Node* root)
{
    if(root==null)
        return;
    print(root->left);
    cout<<root->key<<" ";
    print(root->right);
}

void printBFS(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->key<<" ";
        if(temp->left!=null)
            q.push(temp->left);
        if(temp->right!=null)
            q.push(temp->right);
    }
}

void printDFS(Node* root)
{
    stack<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.top();
        q.pop();
        cout<<temp->key<<"\n";
        if(temp->right!=null)
            q.push(temp->right);
        if(temp->left!=null)
            q.push(temp->left);
    }
}

int main()
{
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    printBFS(root);
    cout<<"\nFinished"<<endl;
}