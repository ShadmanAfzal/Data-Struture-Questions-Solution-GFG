#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = null;
    }
};

int getMaxWidth(Node* root)
{
    if(root==null)
        return 0;
    int maxWidth = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        maxWidth = max(count,maxWidth);

        while(count--)
        {
            Node* top = q.front();
            q.pop();
            if(top->left!=null)
                q.push(top->left);
            if(top->right!=null)
                q.push(top->right);
        }
    }
    return maxWidth;
}

void printLevelOrder(Node* root)
{
    if(root==null)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* top = q.front();
        cout<<top->data<<" ";
        q.pop();
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
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
    root->right->right->right = new Node(7);
    int width = getMaxWidth(root);
    printLevelOrder(root);
    cout<<endl<<"Max Width "<<width<<endl;
}