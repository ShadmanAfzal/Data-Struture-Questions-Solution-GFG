#include <bits/stdc++.h>
#define V 9
using namespace std;

int minIndex(vector<int> value, vector<bool> visited)
{
    int minVal = INT_MAX, index;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && value[i] < minVal)
        {
            minVal = value[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int starting)
{
    vector<int> value(V, INT_MAX);
    vector<bool> visited(V, false);
    value[0] = 0;
    int count = V - 1;
    while (count--)
    {
        int u = minIndex(value, visited);
        visited[u] = true;    
        for (int v = 0; v < V; v++)
            {
                if (!visited[v] && graph[u][v] && value[u] != INT_MAX && value[u] + graph[u][v] < value[v])
                {
                    value[v] = value[u] + graph[u][v];
                }
            }
    }

    for (int i = 0; i < V; i++)
    {
        cout << value[i] << " ";
    }
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);
}