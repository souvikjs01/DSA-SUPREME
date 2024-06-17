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

    void BFStraversal(T src, unordered_map<T, bool>&vis){
        queue<T> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " ";
            for(auto nbr: adjList[frontNode]){
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
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
    for(char i='a'; i<='f'; i++){
        if(!vis[i]){
            g.BFStraversal('a', vis);
        }
    }

    return 0;
}