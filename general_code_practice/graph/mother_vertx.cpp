/*
MotherVertex: This is a vertx from there we can traverse to all the vertx present in graph.
*/


#include<bits/stdc++.h>
using namespace std;

void make_graph(vector <int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}

void DFSutil(vector<int> adj[], vector<bool> visited, int src){
    visited[src]=true;
    cout<<src<<" ";
    for(auto x:adj[src]){
        if(!visited[x]){
            DFSutil(adj, visited, x);
        }
    }
}

void DFS(vector<int> adj[], int V){
    vector<bool> visited(V, false);

    int v=0;
    DFSutil(adj, visited, 5);
/*    for(int i=0; i<V;i++){
        if(!visited[i]){
            DFSutil(adj, visited, i);
            v=i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFSutil(adj, visited, v);

    for(int i=0;i<V;i++){
        if(!visited[i])
            return -1;
    }
    return v;*/
}

int main(){
    int vertx;
    cin>>vertx;

    vector<int> adj[vertx];

    make_graph(adj, 0, 1);
    make_graph(adj, 0, 2);
    make_graph(adj, 1, 3);
    make_graph(adj, 4, 1);
    make_graph(adj, 6, 4);
    make_graph(adj, 5, 6);
    make_graph(adj, 5, 2);
    make_graph(adj, 6, 0);
    DFS(adj, vertx);
    //cout<<DFS(adj, vertx);
}
