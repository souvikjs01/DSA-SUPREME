#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// adjacent list:
class Graph{
public:
    unordered_map<int, vector<int> >adjList;
    void addEdge(int u, int v, bool direction){
        // direction = 1 => directed graph
        if(direction == 1){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjlist(){
        for(auto mp: adjList){
            cout << mp.first << " {";
            for(auto j: mp.second){
                cout << j << "," ;
            }
            cout<< "}"<< endl;
        }
    }
};
int main(){
    Graph g;
    // directed graph:
    // g.addEdge(0, 1, 1);
    // g.addEdge(0, 2, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    
    // undirected graph:
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0); 
    g.printAdjlist();

    return 0;
}