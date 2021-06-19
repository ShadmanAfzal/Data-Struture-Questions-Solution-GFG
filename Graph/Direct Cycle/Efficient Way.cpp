#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;

    vector<int> *adj;

    Graph(int v)
    {
        this->V = v;
        adj = new vector<int>[v];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool isCylicUtil(vector<bool> isVisited, vector<bool> &recStack, int curr)
    {
        if (!isVisited[curr]) {
            isVisited[curr] = true;
            recStack[curr] = true;

            vector<int>::iterator it;

            for(it = adj[curr].begin(); it!= adj[curr].end(); it++) {
                if(!isVisited[*it] && isCylicUtil(isVisited,recStack,curr)) return true;
                else if(recStack[*it]) return true;
            }

        }
        recStack[curr] = false;
        return false;
    }

    bool isCylic()
    {
        vector<bool> isVisited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (isCylicUtil(isVisited, recStack, i))
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << g.isCylic() << endl;
}