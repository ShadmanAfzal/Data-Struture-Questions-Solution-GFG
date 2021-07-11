#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n){

    int maxval = INT_MIN;
    int index = 0;
    for(int i=0;i<n;i++){
        if(maxval<arr[i])
        {
            maxval = arr[i];
            index = i;
        }
    }

    int i=index-2, j = index+2;

    while(i >= 0){
        maxval += arr[i];
        i = i - 2;
    }

    while(j<n){
        maxval += arr[j];
        j = j + 2;
    }

    return maxval;

}

int main()
{
    int arr[] = {1, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findMaxSum(arr,n);
}