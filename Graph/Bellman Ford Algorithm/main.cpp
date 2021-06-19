#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, des, weight;
};

class Graph
{
public:
    int v, e;

    Edge *edge;

    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        this->edge = new Edge[e];
    }
};

void BellmanFord(Graph graph, int src)
{
    int v = graph.v;
    int e = graph.e;
    vector<int> distance(v, INT_MAX);
    distance[src] = 0;

    int count = v - 1;

    while (count--)
    {
        for (int i = 0; i < e; i++)
        {
            int u = graph.edge[i].src;
            int v = graph.edge[i].des;
            int weight = graph.edge[i].weight;

            if (distance[u] != INT_MAX and distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        int u = graph.edge[i].src;
        int v = graph.edge[i].des;
        int weight = graph.edge[i].weight;

        if (distance[u] != INT_MAX and distance[v] > distance[u] + weight)
        {
            cout << "Graph contain negative edge" << endl;
            return;
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << distance[i] << " ";
    }
}

int main()
{

    Graph graph(5, 8);
    graph.edge[0].src = 0;
    graph.edge[0].des = 1;
    graph.edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph.edge[1].src = 0;
    graph.edge[1].des = 2;
    graph.edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph.edge[2].src = 1;
    graph.edge[2].des = 2;
    graph.edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph.edge[3].src = 1;
    graph.edge[3].des = 3;
    graph.edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph.edge[4].src = 1;
    graph.edge[4].des = 4;
    graph.edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph.edge[5].src = 3;
    graph.edge[5].des = 2;
    graph.edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph.edge[6].src = 3;
    graph.edge[6].des = 1;
    graph.edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph.edge[7].src = 4;
    graph.edge[7].des = 3;
    graph.edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}