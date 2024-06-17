// DFS traversal:
// BFS Traversal:
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// weighted graph

template <typename T>
class Graph{
public:
    unordered_map<T, vector<pair<T, T>>> adjList;
    void addEdge(T u, T v, T wt, bool direction){
        // direction = 1 => directed graph
        if(direction == 1){
            adjList[u].push_back(make_pair(v,wt));
        }
        else{
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjlist(){
        for(auto mp: adjList){
            cout << mp.first << " {";
            for(auto pr: mp.second){
                cout << "{" << pr.first << " ," << pr.second;
            }
            cout<< "}" << endl;
        }
    }

    void DFStraversal(T src, unordered_map<T, bool>&vis){
        vis[src] = true;
        cout << src << " ";

        for(auto nbr: adjList[src]){
            if(!vis[nbr.first]){
                DFStraversal(nbr.first, vis);
            }
        }
    }
};
int main(){
    Graph<char> g;
    g.addEdge('a', 'b', 1, 0);
    g.addEdge('a', 'c', 1, 0);
    g.addEdge('b', 'c', 1, 0);
    g.addEdge('c', 'd', 1, 0);
    g.addEdge('c', 'e', 1, 0);
    g.addEdge('e', 'f', 1, 0);
    
    unordered_map<char, bool>vis;
    // g.DFStraversal('a', vis);
    for(char node='a'; node<='f'; node++){
        if(!vis[node]){
            g.DFStraversal(node, vis);
        }
    }

    return 0;
}