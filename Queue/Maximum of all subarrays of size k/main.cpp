#include <bits/stdc++.h>
using namespace std;

void maxSumSubArray(int arr[],int n,int k)
{
    deque<int> solution;
    int i;
    for(i=0;i<k;++i)
    {
        while(!solution.empty() && arr[i]>=arr[solution.back()])
            solution.pop_back();
        solution.push_back(i);
    }
    for(;i<n;++i)
    {
        cout<<arr[solution.front()]<<" ";
        while(!solution.empty() && solution.front()<=i-k)
        {
            solution.pop_front();
        }
        while(!solution.empty() && arr[i]>=arr[solution.back()])
            solution.pop_back();
        solution.push_back(i);
    }
    cout<<arr[solution.front()]<<endl;
}

int main()
{
  int n,k;
  int arr[n];
  cin>>n;
  cin>>k;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  maxSumSubArray(arr,n,3);
  return 0;
}