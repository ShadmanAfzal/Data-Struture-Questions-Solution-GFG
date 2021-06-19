#include <bits/stdc++.h>
#define v 3
using namespace std;

int minValue(vector<int> values, vector<bool> mstset)
{
    int minvalue = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (mstset[i] == false && values[i] < minvalue)
        {
            minvalue = values[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int graph[v][v])
{
    vector<int> values(v, INT_MAX);
    vector<bool> mstset(v, false);
    values[0] = 0;
    int minCost = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int u = minValue(values, mstset);
        mstset[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] && mstset[j] == false && graph[u][j] < values[j])
            {
                values[j] = graph[u][j];
                minCost += values[j];
            }
        }
    }
    return minCost;
}

int main()
{
    int graph[v][v] = {0};
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++){
            cin>>graph[i][j];
        }
    }
    cout << primMST(graph) << endl;
}