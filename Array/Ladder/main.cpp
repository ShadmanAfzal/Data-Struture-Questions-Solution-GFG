#include <bits/stdc++.h>
using namespace std;

void ladder(int arr[], int size) // O(n*n)
{
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] <= arr[j])
                break;
        }
        if (j == size)
        {
            cout << arr[i] << " ";
        }
    }
}

void efficientWay(int arr[], int size) // O(n)
{
    int maximum = arr[size-1];

    for(int i=size-1; i>=0;i--){
        if(arr[i]>=maximum){
            maximum = arr[i];
            cout<<arr[i]<<" ";
        }
    }
} 



int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    efficientWay(arr, size);
}