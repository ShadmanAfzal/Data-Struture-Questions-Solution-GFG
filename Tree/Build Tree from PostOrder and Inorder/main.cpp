#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    preOrder(node->left);

    preOrder(node->right);
}

Node *buildTree(int in[], int post[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    cout<<"finshed";
    return 0;
}

Node *generate(int in[], int post[], int start, int end,map<int,int> &hash)
{
    static int postIndex = end;
    if (start > end)
        return NULL;
    Node *root = new Node(post[postIndex--]);
    if(start==end)
        return  root;
    int index = hash[root->data];
    root->right = generate(in, post, index + 1, end,hash);
    root->left = generate(in, post, start, index - 1,hash);
    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    map<int, int> cache;
    for (int i = 0; i < n; i++)
        cache[in[i]] = i;
    Node *root = generate(in, post, 0, n - 1,cache);
    return root;
}
