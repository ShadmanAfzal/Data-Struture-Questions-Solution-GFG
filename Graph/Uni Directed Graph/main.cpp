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
        adj[w].push_back(v);
    }

    bool isCylicUtil(vector<bool> &isVisited,int curr,int parent){
        
        vector<int>::iterator it;
        isVisited[curr] = true;
        for(it = adj[curr].begin(); it!=adj[curr].end();it++) {
            if(!isVisited[*it]) {
                if(isCylicUtil(isVisited,*it,curr)) return true;
            }
            else if(*it!=parent) {
                return true;
            }
        }
        return false;
    }

    bool isCylic() {
        vector<bool> isVisited(V,false);

        for(int i=0;i<V;i++) {
            if(!isVisited[i]) {
                if(isCylicUtil(isVisited,i,-1)) return true;
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
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    string res = g1.isCylic()?"Graph contains a cycle":"No cycle found";
    cout<<res;
}