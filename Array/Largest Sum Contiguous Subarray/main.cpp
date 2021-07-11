#include <bits/stdc++.h>
using namespace std;

int findLargestSumSubarray(int arr[],int size)
{
    int maximum_so_far = INT_MIN, maximum = 0;

    for(int i=0;i<size;i++){
        maximum += arr[i];
        if(maximum_so_far < maximum)
            maximum_so_far = maximum;
        if(maximum<0){
            maximum = 0;
        }
    }
    return maximum_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<findLargestSumSubarray(arr,size);
}