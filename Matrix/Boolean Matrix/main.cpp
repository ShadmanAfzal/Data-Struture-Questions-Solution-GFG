#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<bool>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j : matrix[i])
            cout << j << " ";
        cout << endl;
    }
}

void addOnes(vector<vector<bool>> &matrix, int x,int y,int row,int col){
    
    for(int i=x;i<col;i++)
        matrix[i][x] = true;

    for(int i=y;i<row;i++)
        matrix[y][i] = true;
}

void modifyMatrix(vector<vector<bool>> &matrix){

    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==1)
                addOnes(matrix,i,j,row,col);
        }
    }

}

int main()
{
    vector<vector<bool>> mat{{1, 0, 0, 1},
                             {0, 0, 1, 0},
                             {0, 0, 0, 0}};

    cout << "Original Matrix\n";
    printMatrix(mat);
    modifyMatrix(mat);
    cout << "Modified Matrix\n";
    printMatrix(mat);
}