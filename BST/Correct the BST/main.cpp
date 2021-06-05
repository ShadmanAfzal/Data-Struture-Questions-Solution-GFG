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
    cout << root->data << " ";
    inorder(root->right);
}

void correctBSTGenerator(Node *root, Node *&first, Node *&middle, Node *&last, Node *&prev)
{
    if (root == NULL)
        return;
    correctBSTGenerator(root->left, first, middle, last, prev);

    if (prev && root->data < prev->data)
    {
        if (first == NULL)
        {
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;
    correctBSTGenerator(root->right, first, middle, last, prev);
}

// void swap( int* a, int* b )
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

void correctBST(Node *root)
{
    Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    correctBSTGenerator(root, first, middle, last, prev);
    if (first and last)
        swap((first->data), (last->data));
    else if (first and middle)
        swap((first->data), (middle->data));
    inorder(root);
}

int main()
{
    // Node *root = new Node(6);
    // root->left = new Node(10);
    // root->right = new Node(2);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right->right = new Node(12);
    // root->right->left = new Node(7);
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    inorder(root);
    cout << endl;
    correctBST(root);
}