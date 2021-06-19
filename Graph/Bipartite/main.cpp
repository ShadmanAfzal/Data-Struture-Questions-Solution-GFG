#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<int> *adj;

    Graph(int verticles)
    {
        v = verticles;
        adj = new vector<int>[verticles];
    }

    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }

    bool checkBipartite()
    {
        queue<int> s;
        s.push(0);
        vector<int> color(v, -1);
        color[0] = 1;
        while (!s.empty())
        {
            int curr = s.front();
            s.pop();
            for (int i = 0; i < adj[curr].size(); i++)
            {
                if (color[adj[curr][i]] == color[curr])
                    return false;
                else if (color[adj[curr][i]] == -1)
                {
                    color[adj[curr][i]] = 1 - color[curr];
                    s.push(adj[curr][i]);
                }
            }
        }
        return true;
    }

    void BFS()
    {
        deque<int> dq;
        dq.push_back(0);
        vector<int> visited(v, false);
        visited[0] = true;
        while (!dq.empty())
        {
            int temp = dq.front();
            dq.pop_front();
            cout << temp << " ";
            vector<int>::iterator it;
            for (it = adj[temp].begin(); it != adj[temp].end(); ++it)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    dq.push_back(*it);
                }
            }
        }
    }
};

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    cout << graph.checkBipartite() << endl;
}
