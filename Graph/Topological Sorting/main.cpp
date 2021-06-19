#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int v;
        vector<int> *adj;

        Graph(int verticles){
            this->v = verticles;
            this->adj = new vector<int>[verticles];
        }

        void addEdge(int x,int y){
            adj[x].push_back(y);
        }


        void DFS(vector<bool> &isvisited, stack<int> &s, int curr){
            isvisited[curr] = true;

            vector<int>::iterator it;

            for(it = adj[curr].begin(); it != adj[curr].end(); it++){
                if(!isvisited[*it]){
                    DFS(isvisited, s, *it);
                }
            }

            s.push(curr);
        }

        void TopologicalSorting(){
            vector<bool> isvisited(v,false);
            stack<int> s;
            for(int i=0;i<v;i++){
                if(!isvisited[i]){
                    DFS(isvisited,s,i);
                }
            }
            cout<<"Topological Sorting"<<endl;
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.TopologicalSorting();
}