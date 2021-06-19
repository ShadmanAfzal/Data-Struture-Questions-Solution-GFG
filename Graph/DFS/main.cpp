#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<int> *adj;

    Graph(int v)
    {
        this->V = v;
        adj = new vector<int>[v];
    }

    void addEdge(int x,int y)
    {
        this->adj[x].push_back(y);
    }

    void DFS(int i)
    {
        stack<int> s;
        s.push(i);

        vector<bool> isVisited(V,false);

        isVisited[i] = true;

        vector<int>::iterator it;

        while(!s.empty())
        {
            int temp = s.top();
            s.pop();
            cout<<temp<<" ";
            for(it = adj[temp].begin(); it != adj[temp].end(); it++)
            {
                if(!isVisited[*it])
                {   
                    isVisited[*it] = true;
                    s.push(*it);
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
    g.addEdge(3, 3);
    // g.addEdge(2, 0);
    g.DFS(0);
}