#include <bits/stdc++.h>
using namespace std;

class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int v, int w)
    {
        this->v = v;
        this->weight = w;
    }

    int getV()
    {
        return this->v;
    }

    int getWeight()
    {
        return this->weight;
    }
};

class Graph
{
public:
    int v;
    vector<AdjListNode> *adj;

    Graph(int v)
    {
        this->v = v;
        this->adj = new vector<AdjListNode>[v];
    }

    void addEdge(int x, int y, int weight)
    {
        AdjListNode node(y, weight);
        adj[x].push_back(node);
    }

    void topologicalSorting(int curr, vector<bool> &visited, stack<int> &s)
    {
        visited[curr] = true;

        vector<AdjListNode>::iterator it;

        for (it = adj[curr].begin(); it != adj[curr].end(); ++it)
        {
            if (!visited[(*it).getV()])
            {
                topologicalSorting((*it).getV(), visited, s);
            }
        }
        s.push(curr);
    }

    void LongestPath(int source)
    {
        stack<int> s;
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                topologicalSorting(i, visited, s);
            }
        }

        vector<int> distance(v, INT_MIN);
        distance[source] = 0;

        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            vector<AdjListNode>::iterator it;
            if (distance[u] != INT_MIN)
            {
                for (it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    if (distance[(*it).getV()] < distance[u] + (*it).getWeight())
                    {
                        distance[(*it).getV()] = distance[u] + (*it).getWeight();
                    }
                }
            }
        }
        cout << "Distance from source to all Node" << endl;
        for (int i = 0; i < v ; i++)
        {
            cout << distance[i] << " ";
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.LongestPath(1);
}