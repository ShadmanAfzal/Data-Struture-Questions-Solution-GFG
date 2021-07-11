#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> tempArray{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = tempArray.size();
    int x = 2;
    for (int k = 0; k < n; k++)
    {
        int temp = x;
        vector<int> arr = tempArray;
        for (int i = k; i < n; i++)
        {
            if (arr[i] == 0 and temp > 0)
            {
                temp--;
                arr[i] = 1;
            }
        }
        int count = 0;
        for (int i = k; i < n; i++)
        {
            if (arr[i] == 1)
                count++;
            else
                break;
        }
        cout << count << " ";
    }
}