#include <bits/stdc++.h>
using namespace std;

class  Graph{
public:
    int v;
    vector<int> *adj;

    Graph(int v){
        this->v = v;
        this->adj = new vector<int>[v];
    }

    void addEdge(int x,int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void DFS(int curr,vector<bool> &isvisited){
        isvisited[curr] = true;
        
        vector<int>::iterator it;

        for(it = adj[curr].begin(); it != adj[curr].end(); ++it){
            if(!isvisited[*it])
                DFS(*it,isvisited);
        }
    }

    bool isConnected(){
        vector<bool> isvisited(v,false);
        DFS(0,isvisited);

        for(int i=0;i<isvisited.size();i++){
            if(isvisited[i]==false and adj[i].size()>0)
                return false;
        }

        return true;
    }


    int isEuler(){
        if(isConnected()==false)
            return 0;
        
        int odd = 0;
        vector<int> nodes(v,0);

        for(int i=0;i<v;i++){
            nodes[i] = adj[i].size();    
        }
        
        for(int i=0;i<v;i++){
            if(nodes[i]%2!=0){
                odd++;
            }
        }

        if(odd>2)
            return 0;
        
        return odd?1:2;
    }

    void checkisEulerian(){
        int result = isEuler();
        if(result==1){
            cout<<"Graph is Euler path\n";
        }
        else if(result==2){
            cout<<"Graph has Euler cycle\n";
        }
        else if(result==0){
            cout<<"Graph is not eulerian\n";
        }
    }


};

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.checkisEulerian();

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.checkisEulerian();


    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.checkisEulerian();

    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.checkisEulerian();

    Graph g5(3);
    g5.checkisEulerian();
}