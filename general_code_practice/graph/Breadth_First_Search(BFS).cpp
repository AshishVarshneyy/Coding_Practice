/*
Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures.
It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'[1]),
and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
*/

#include<bits/stdc++.h>
using namespace std;


void make_graph(vector <int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}


void BFS(vector <int> adj[], int vertx, int src){
    list<int> que;
    vector<bool> visited(vertx, false);

    visited[src]=true;
    que.push_back(src);

    while(!que.empty()){
            src=que.front();
            cout<<src<<" ";
            que.pop_front();

            for(auto x:adj[src]){
                if(!visited[x]){
                    visited[x]=true;
                    que.push_back(x);
                }
            }
    }
}


int main(){
    int vertx;
    cin>>vertx;

    vector <int> adj[vertx];

    make_graph(adj, 0, 1);
    make_graph(adj, 0, 2);
    make_graph(adj, 1, 2);
    make_graph(adj, 2, 0);
    make_graph(adj, 2, 3);
    make_graph(adj, 3, 3);
    make_graph(adj, 4, 5);

    BFS(adj, vertx, 3);
    return 0;
}
