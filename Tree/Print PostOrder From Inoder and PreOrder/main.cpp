#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;
    }
        cout<<"endl";
}
// } Driver Code Ends

class Node
{
    public:
        int key;
        Node* left, *right;
        Node(int data)
        {
            this->key = data;
            this->left = this->right = NULL;
        }
};

void print(Node* root)
{
    if(!root)
        return;
    print(root->left);
    print(root->right);
    cout<<root->key<<" ";
}

map<int,int> cache(int in[],int n)
{
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[in[i]] = i;
    }
    return mp;
}

Node* buildTree(int in[],int pre[],int start,int last,map<int,int> mp)
{
    static int preIndex = 0;
    if(start>last)
        return NULL;
    
    Node* root = new Node(pre[preIndex++]);
    if(start==last)
        return root;
    int index = mp[root->key];
    root->left = buildTree(in,pre,start,index-1,mp);
    root->right = buildTree(in,pre,index+1,last,mp);
    return root;
}

void printPostOrder(int in[], int pre[], int n)
{
    map<int, int> mp = cache(in,n);
    Node* root = buildTree(in,pre,0,n-1,mp);
    print(root);
}
