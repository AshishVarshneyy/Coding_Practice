/*
Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures.
The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph)
and explores as far as possible along each branch before backtracking.
*/

#include<bits/stdc++.h>
using namespace std;

void make_graph(vector<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}

void DFSutil(vector<int> adj[], vector <bool>visitor, int src){
    visitor[src]=true;
    cout<<src<<" ";
    for(auto x:adj[src]){
        if(!visitor[x]){
            DFSutil(adj, visitor, x);
        }
    }
}

void DFS(vector<int> adj[], int V, int src){

    vector <bool>visitor(V, false);
    DFSutil(adj, visitor, src);
}

int main(){

    int vertx, edges;
    cin>>vertx>>edges;

    vector<int>adj[vertx];

    make_graph(adj, 0, 1);
    make_graph(adj, 0, 2);
    make_graph(adj, 1, 2);
    make_graph(adj, 2, 0);
    make_graph(adj, 2, 3);
    make_graph(adj, 3, 3);

    DFS(adj, vertx, 2);
    return 0;
}
