#include <bits/stdc++.h>
using namespace std;

class BST{
public:
    int data;
    int freq;
    BST *left, *right;

    BST(int data, int freq){
        this->data = data;
        this->freq = freq;
        this->left = this->right = NULL;
    }
};

class dataFreq{
public:
    int data;
    int freq;
};

BST* insert(BST *root,int data){
    
    if(root==NULL)
        return new BST(data,1);
    
    if(root->data == data){
        root->freq += 1;
        return root;
    }

    if(root->data > data)
        root->left = insert(root->left,data);
    else if(root->data < data)
        root->right = insert(root->right,data);
    
    return root;
}

void store(dataFreq count[], int *index, BST *root){
    
    if(!root) return;

    store(count,index,root->left);

    count[*index].freq = root->freq;
    count[*index].data = root->data;
    (*index)++;
    store(count,index,root->right);

}

int compare(const void *a, const void *b){
    return ((*(const dataFreq*)b).freq) - ((*(const dataFreq*)a).freq);
}

void sortByFreq(int arr[], int size){

    BST *root = NULL;

    for(int i=0;i<size;i++){
        root = insert(root,arr[i]);
    }


    dataFreq count[size];
    int index = 0;
    store(count,&index,root); 


    qsort(count,index,sizeof(count[0]),compare);  

    int j = 0;
    for(int i=0;i<index;i++){
        for(int freq=count[i].freq; freq>0; freq--){
            arr[j++] = count[i].data;
        }
    }
    

}

int main()
{
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortByFreq(arr,size);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}