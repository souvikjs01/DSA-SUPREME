#include<iostream>
#include<vector>
#include<unordered_map>
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
};
int main(){
    Graph<int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,10,1);
    g.addEdge(1,3,20,1);
    g.addEdge(2,3,50,1);
    g.printAdjlist(); 

    return 0;
}