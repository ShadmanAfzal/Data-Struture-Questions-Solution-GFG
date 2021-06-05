
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



Node* buildTree(string str)
{
    
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    
    
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    
    Node* root = newNode(stoi(ip[0]));

    
    queue<Node*> queue;
    queue.push(root);

    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        
        Node* currNode = queue.front();
        queue.pop();

        
        string currVal = ip[i];

        
        if(currVal != "N") {

            
            currNode->left = newNode(stoi(currVal));

            
            queue.push(currNode->left);
        }

        
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        
        if(currVal != "N") {

            
            currNode->right = newNode(stoi(currVal));

            
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 


class Solution {
public:
    void printLeftTree(Node* root,vector<int> *sol)
    {
        if(!root)
            return;
        if(root->left)
        {
            sol->push_back(root->data);
            printLeftTree(root->left,&sol);
        }
        if(root->right)
        {
            sol->push_back(root->data);
            printLeftTree(root->right,&sol);
        }
    }
    
    void printRightTree(Node* root,vector<int> *sol)
    {
        if(!root)
            return;
        if(root->right)
        {
            printLeftTree(root->right,&sol);
            sol->push_back(root->data);
        }
        if(root->left)
        {
            printLeftTree(root->left,&sol);
            sol->push_back(root->data);
        }
    }
    
    void printLeafs(Node* root,vector<int> *sol)
    {
        if(!root)
            return;
        printLeafs(root->left,&sol);
        if(root->left==NULL && root->right==NULL)
        {
            sol->push_back(root->data);
        }
        printLeafs(root->right,&sol);
        return;
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> sol;
        sol.push_back(root->data);
        printLeftTree(root->left,&sol);
        printLeafs(root->left,&sol);
        printLeafs(root->right,&sol);
        printRightTree(root->right,&sol);
        return sol;
    }
};





int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  