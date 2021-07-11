#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndofWord;
};

TrieNode *getNode()
{
    TrieNode *ptr = new TrieNode;
    ptr->isEndofWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        ptr->children[i] = NULL;
    }

    return ptr;
}

void insert(TrieNode *root, string str)
{
    TrieNode *ptr = root;

    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';

        if (!ptr->children[index])
        {
            ptr->children[index] = getNode();
        }
        ptr = ptr->children[index];
    }
    
    ptr->isEndofWord = true;
}

bool search(TrieNode *root, string str)
{
    TrieNode *ptr = root;

    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        if (ptr->children[index] == NULL)
        {
            return false;
        }

        ptr = ptr->children[index];
    }

    return (ptr != NULL and ptr->isEndofWord);
}

bool isEmpty(TrieNode* root){

    for(int i = 0; i<ALPHABET_SIZE;i++){
        if(root->children[i])
            return false;
    }

    return true;
}

TrieNode* remove(TrieNode* root,string str,int depth){
    if(!root)
        return NULL;

    if(depth == str.size()){
        if(root->isEndofWord)
            root->isEndofWord = false;

        if(isEmpty(root))
            delete(root);
            root = NULL;
        
        return root;
    }       

    int index = str[depth]  - 'a';

    root->children[index] = remove(root->children[index],str,depth+1);

    if(isEmpty(root) and root->isEndofWord==false){
        delete(root);
        return NULL;
    }

    return root;
}

string longestPrefix(TrieNode *root,string str){
    
    TrieNode* ptr = root; 
    string prefix = "";
    int prevMatch = 0;

    for(int i=0;i<str.size();i++){
        int index = str[i] - 'a';

        if(!ptr->children[index])
            return prefix;
        
        prefix += str[i];

        ptr = ptr->children[index];

        if(ptr->isEndofWord)
            prevMatch = i + 1;
    }

    if(ptr->isEndofWord){
        return prefix.substr(0,prevMatch);
    }
    return prefix;
}

int main()
{
    string keys[] = {
        "the", "a", "there",
        "answer", "any", "by",
        "bye", "their"};

    TrieNode *root = getNode();

    int n = sizeof(keys)/sizeof(keys[0]);

    for(int i=0;i<n;i++)
        insert(root,keys[i]);
    insert(root,"children");
    cout<<longestPrefix(root,"child");

    // cout<<search(root,"there")<<endl;
    // root = remove(root,"there",0);
    // cout<<search(root,"there")<<endl;
}