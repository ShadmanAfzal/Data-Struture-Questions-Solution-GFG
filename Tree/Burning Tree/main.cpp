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

int burnTreeUntil(Node* root,int target,queue<Node*> &q,int *time)
{
    if(root==NULL)
        return 0;
    if(root->data == target)
    {
        cout<<root->data<<"\n";
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        (*time)++;
        return 1;
    }

    int a = burnTreeUntil(root->left,target,q,time);
    if(a == 1)
    {
        int qsize = q.size();
        while(qsize--)
        {
            Node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        if(root->right!=NULL)
            q.push(root->right);

        cout<<root->data<<" "<<endl;
        return 1;
    }

    int b = burnTreeUntil(root->right,target,q,time);

    if(b == 1)
    {
        int qsize = q.size();
        while(qsize--)
        {
            Node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        } 
        if(root->left!=NULL)
            q.push(root->left);

        cout<<root->data<<" "<<endl;

        return 1;
    }
}

void burnTree(Node* root,int target,int *time)
{
    queue<Node*> q;
    burnTreeUntil(root,target,q,time);
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        q.pop();
        (*time)++;
    }
    
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(13);
    root->right->left = new Node(14);
    root->right->right = new Node(15);
    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);
    int targetNode = 14;
    int time = 0;
    burnTree(root,targetNode,&time);
    cout<<endl<<time;
    return 0;
}