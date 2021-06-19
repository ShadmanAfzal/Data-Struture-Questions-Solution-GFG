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

    bool checkUntil(vector<int> adj[],vector<bool> isVisited, int curr)
    {
        if(isVisited[curr]) return true;

        isVisited[curr] = true;
        bool FLAG = true;
        for(int i=0;i<adj[curr].size();i++)
        {
            FLAG = checkUntil(adj,isVisited,adj[curr][i]);
            if(FLAG)
                return true;
            isVisited[i] = false;
        }
        return false;
    }


    bool isCylic()
    {
        vector<bool> isVisited(V,false);
        bool FLAG = false;

        for(int i=0;i<V;i++)
        {
            isVisited[i] = true;
            for(int j=0;j<adj[i].size();j++)
            {
                FLAG = checkUntil(adj,isVisited,adj[i][j]);
                if(FLAG)
                    return true;
                isVisited[i] = true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    // g.BFS(0);

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    cout<<g2.isCylic()<<endl;
}