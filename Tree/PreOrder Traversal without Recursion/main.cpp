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

void printPreOrder(Node* root)
{
    Node* temp = root;
    stack<Node*> s;
    while (!s.empty() || temp!=null)
    {
        while(temp!=null)
        {
            s.push(temp);
            cout<<s.top()->key<<endl;
            temp=temp->left;
        }
        temp = s.top();
        s.pop();
        temp=temp->right;
    }
    
}

void postOrder(Node* node) {
    vector<int> sol;
    stack<Node*> s;
    Node* curr = node;
    while(!s.empty() || curr != NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
        cout<<s.top()->key;
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
    postOrder(root);
    cout<<"\nFinished"<<endl;
}