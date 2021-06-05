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

void findCeilFloor(Node *root, int &ceil, int &floor, int key)
{
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            floor = root->data;
        }
        else if (root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->data == key)
    {
        if (root->left)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }
    if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    return;
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
    // int ceil = -1,floor = -1;
    Node *pre = NULL, *succ = NULL;
    findPreSuc(root, pre, succ, 14);
    cout << "Pre "<<pre->data;
    cout << "\n";
    cout << "Suc "<<succ->data;
    cout << "\nfinished" << endl;

    // findCeilFloor(root, ceil, floor, 15);
    // cout<<ceil<<" "<<floor<<endl;
}