#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<int> *adj;

    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }

    void fillOrder(int curr, stack<int> &s,vector<bool> &visited)
    {
        visited[curr] = true;

        vector<int>::iterator it;

        for (it = adj[curr].begin(); it != adj[curr].end(); ++it)
        {
            if (!visited[*it])
            {
                fillOrder(*it, s, visited);
            }
        }
        s.push(curr);
    }

    Graph getTranspose()
    {
        Graph g(v);
        for (int i = 0; i < v; i++)
        {
            vector<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                g.adj[*it].push_back(i);
            }
        }
        return g;
    }

    void DFSUntil(int curr, vector<bool> &visisted)
    {
        visisted[curr] = true;

        cout << curr << " ";

        vector<int>::iterator it;

        for (it = adj[curr].begin(); it != adj[curr].end(); it++)
        {
            if (!visisted[*it])
                DFSUntil(*it,visisted);
        }
    }

    void printSCC()
    {
        stack<int> s;
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                fillOrder(i, s, visited);
        }
        Graph transpose = getTranspose();

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        while (!s.empty())
        {
            int v = s.top();
            s.pop();

            if (!visited[v])
            {
                
                transpose.DFSUntil(v, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.printSCC();
}