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

    void addEdge(int v,int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int x)
    {
        vector<bool> isVisited(V,false);

        deque<int> dq;

        dq.push_back(x);
        isVisited[x] = true;
        vector<int>::iterator it;
        while(!dq.empty())
        {
            x = dq.front();
            dq.pop_front();
            cout<<x<<" ";
            for(it = adj[x].begin(); it != adj[x].end(); it++)
            {
                if(!isVisited[*it])
                {
                    dq.push_back(*it);
                    isVisited[*it] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 3);
    g.BFS(0);
}