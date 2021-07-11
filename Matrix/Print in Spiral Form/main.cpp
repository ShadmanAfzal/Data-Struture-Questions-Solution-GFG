#include <bits/stdc++.h>
using namespace std;

void printSpiral(vector<vector<int>> arr){
    
    int row = arr.size();
    int col = arr[0].size();
    
    vector<vector<bool>> isvisited(row,vector<bool>(col,false));

    int k=0,l=0;
    while(k<row and l<col){

        for(int i=l;i<col;i++){
            cout<<arr[k][i]<<" ";
        }
        k++;

        for(int i=k;i<row;i++){
            cout<<arr[i][col-1]<<" ";
        }
        col--;

        if(k<row){
            for(int i=col-1;i>=l;i--)
                cout<<arr[row-1][i]<<" ";
        }
        row--;

        if(l<col){
            for(int i=row-1;i>=k;i--)
                cout<<arr[i][l]<<" ";
        }
        l++;

    }
}

int main()
{
    vector<vector<int>> arr{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};

    printSpiral(arr);
}