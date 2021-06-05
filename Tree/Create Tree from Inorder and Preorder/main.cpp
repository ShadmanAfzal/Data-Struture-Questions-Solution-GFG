#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node
{
public:
    char key;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->key = key;
        this->left = this->right = null;
    }
};

int searchNode(char pre,char in[],int start,int end);

Node* createTree(char in[],char pre[],int start,int end)
{
    static int preIndex = 0;
    if(start>end)
        return null;
    Node* root = new Node(pre[preIndex++]);
    if(start==end) 
        return root;
    int index = searchNode(root->key,in,start,end);
    root->left = createTree(in,pre,start,index-1);
    root->right = createTree(in,pre,index+1,end);
    return root;
}

int searchNode(char pre,char in[],int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==pre)
            return i;
    }
}
void printInorder(Node* root)
{
    if(root==null)
        return;
    printInorder(root->left);
    cout<<root->key<<" ";
    printInorder(root->right);
    
}

int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int n = sizeof(in)/sizeof(*in);
    Node* root = createTree(in,pre,0,n-1);
    cout<<"here"<<endl;
    printInorder(root);
    return 0;
}