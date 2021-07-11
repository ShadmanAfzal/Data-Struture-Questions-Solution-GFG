#include <bits/stdc++.h>
using namespace std;

void insertInArray(int pos, vector<int> &arr, int curr)
{
    for (int j = arr.size() - 1; j >= pos ; j--)
    {
        arr[j + 1] = arr[j];
    }
    arr[pos] = curr;
}

void insertintoArr(int curr, vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
        {
            arr[i] = curr;
        }
        else if (arr[i] > curr)
        {
            insertInArray(i,arr,curr);
            break;
        }
    }
}

int16_t sortTwoArray(int ar1[], int ar2[], int n1, int n2)
{

    vector<int> arr(n1 + n2, 0);

    for (int i = 0; i < n1; i++)
    {
        arr[i] = ar1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        insertintoArr(ar2[i], arr);
    }

    cout << "Sorted Array" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    return (arr[n1-1]+arr[arr.size()-n2])/2;
}


int EfficentWay(int ar1[], int ar2[],int n){
    int j=0, i = n-1;

    while(ar1[i]>ar2[j] and j<n and i>-1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1,ar1+n);
    sort(ar2,ar2+n);
    return (ar1[n-1]+ar2[0])/2;
}

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout<<EfficentWay(ar1, ar2, n1);
}