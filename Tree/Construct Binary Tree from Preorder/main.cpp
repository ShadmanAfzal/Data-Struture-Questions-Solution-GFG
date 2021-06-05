#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

Node *constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = NULL;
        int n;
        cin >> n;
        int pre[n];
        char preLN[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        for (int i = 0; i < n; i++)
            cin >> preLN[i];
        root = constructTree(n, pre, preLN);
        printInorder(root);
        cout << endl;
    }
    cout << "Finished";
    return 0;
}

Node *buildTree(int *indexptr, int pre[], char preLN[], int n)
{
    int index = *indexptr;
    if (index == n)
        return NULL;
    Node* root = new Node(pre[index]);
    (*indexptr)++;
    if(preLN[index]=='N')
    {
        root->left = buildTree(indexptr,pre,preLN,n);
        root->right = buildTree(indexptr,pre,preLN,n);
    }
    return root;
}

Node *constructTree(int n, int pre[], char preLN[])
{
    static int index = 0;
    Node *root = new Node(pre[index]);
    return buildTree(&index, pre, preLN, n);
}
