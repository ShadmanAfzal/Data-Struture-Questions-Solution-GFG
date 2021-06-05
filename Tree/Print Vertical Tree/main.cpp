#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void findMinMax(Node* root,int *min,int *max,int h)
{
    if(root==NULL) return;
    if(h < *min)
        *min = h;
    else if(h > *max)
        *max = h;
    findMinMax(root->left,min,max,h-1);
    findMinMax(root->right,min,max,h+1);
}

void printNodes(Node* root,int level,int height)
{
    if(root==NULL) return;
    if(level==height)
        cout<<root->data<<" ";
    printNodes(root->left,level,height-1);
    printNodes(root->right,level,height+1);

}

void printVerticleTree(Node* root)
{
    int min=0,max=0;
    int h = 0;
    findMinMax(root,&min,&max,h);
    for(int i=min;i<=max;i++)
    {
        printNodes(root,i,0);
        cout<<endl;
    }
    // cout<<max<<" "<<min<<endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    printVerticleTree(root);
}