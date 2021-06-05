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

int printMaxHeight(Node* root)
{
    if(root==null)
        return 0;
    int left = printMaxHeight(root->left)+1;
    int right = printMaxHeight(root->right)+1;
    return max(left,right);
}

int main()
{
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(10);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(6);
    root->right->right->right->left = new Node(6);

    
    cout<<printMaxHeight(root);
    cout<<"\nFinished"<<endl;
}