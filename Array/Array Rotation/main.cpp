#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int d, int n){
    while(d--){
        int temp = arr[0];  // 1 2 3 4 5 6 7
        for(int i = 0 ; i<n ;i++){
            arr[i] = arr[(i+1)%n];
        }
        arr[n-1] = temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;   
}

void reverse(int arr[], int start, int end){
    while(start<end){
        swap(arr[start++],arr[end--]);
    }
}

void reverseAlgo(int arr[], int d, int n){

    int d = d%n;

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int d = 2;
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,d,n);
    reverseAlgo(arr,d,n);
}