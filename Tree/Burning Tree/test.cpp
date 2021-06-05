#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool isIdentical = false;
    int preorderT[] = {26,10,4,30,6,3};
    int preorderS[] = {10,4,0};
    int i=0,j=0;
    while(i<6 && j<3)
    {
        if(preorderT[i]==preorderS[j])
        {
            i++;
            j++;

            if(j==3)
            {
                isIdentical = true;
                break;
            }
        }
        else
        {
             i = i - j + 1;
             j = 0;
        }
    }
    
    cout<<isIdentical<<" ";
}