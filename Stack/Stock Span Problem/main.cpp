#include <bits/stdc++.h>
using namespace std;

void printSolution(int arr[],int n);

void solve(int price[], int n,int solution[])
{
    stack<int> stock;
    stock.push(0);
    solution[0] = 1;
    for(int i=1;i<n;i++)
    {
        while(!stock.empty() && price[stock.top()] <= price[i])
            stock.pop();
        solution[i] = stock.empty()?(i+1):(i-stock.top());
        stock.push(i);
    }
    printSolution(solution,n);
}

void printSolution(int solution[],int n)
{
    for(int i=0;i<n;i++)
        cout<<solution[i]<<" ";
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price) / sizeof(price[0]);
    int solution[n];
    solve(price, n,solution);
    return 0;
}