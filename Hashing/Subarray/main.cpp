#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 7, 9, 5, 7, 20, 12};
    int arr1[] = {9, 5, 7, 2};
    set<int> helper;
    int size = sizeof(arr)/sizeof(*arr);
    int size1 = sizeof(arr1)/sizeof(*arr1);
    for(int i=0;i<size;i++)
        helper.insert(arr[i]);    
    bool issubarray = true;
    for(int i=0;i<size1;i++)
    {
        
        if(helper.find(arr1[i])==helper.end())
        {
            issubarray = false;
            break;   
        }
    }
    string result = issubarray?"Yes":"No";
    cout<<result<<endl;
}