#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    Node(int data)
    {
        this->key = data;
        this->left = this->right = NULL;
    }
};

void printNode(Node *root, int level)
{
    queue<Node *> q;
    q.push(root);
    while (level--)
    {
        int count = q.size();
        while (count--)
        {
            Node *top = q.front();
            q.pop();
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }
    while (!q.empty())
    {
        cout << q.front()->key << " ";
        q.pop();
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    printNode(root, 0);
    cout << "\nreturn 0" << endl;
}