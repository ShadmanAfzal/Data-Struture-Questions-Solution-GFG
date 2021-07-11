#include <bits/stdc++.h>
using namespace std;


void checkForPairs(int arr[], int size,int sum){
    map<int,int> cache;

    for(int i=0;i<size;i++){
        int temp = sum - arr[i];
        if(cache.count(temp)>0){
            cout<<"{"<<arr[i]<<","<<temp<<"}"<<" ";
        }
        cache[arr[i]] = i;
    }

    
}

int main()
{
    int sum = -2;
    int arr[] = {0, -1, 2, -3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    checkForPairs(arr,size,sum);
}