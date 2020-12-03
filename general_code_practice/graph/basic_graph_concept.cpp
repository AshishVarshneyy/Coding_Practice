#include<bits/stdc++.h>
using namespace std;

void make_graph(vector <int> adj[], int v1, int v2){

    adj[v1].push_back(v2);
    //undirected graph
    adj[v2].push_back(v1);
}


void print_graph(vector <int> adj[], int vertx){
    for(int i=0;i<vertx;i++){
        cout<<i<<"->";

        int ele=0;
        for(auto x:adj[i]){
            ele++;
            if(ele!=adj[i].size())
                cout<<x<<"->";
            else{
                cout<<x;
            }
        }
        cout<<endl;
    }
}
int main(){

    int vertx, edge;
    cin>>vertx>>edge;
    vector <int> adj[vertx];

    make_graph(adj, 0, 1);
    make_graph(adj, 0, 4);
    make_graph(adj, 1, 2);
    make_graph(adj, 1, 3);
    make_graph(adj, 1, 4);
    make_graph(adj, 2, 3);
    make_graph(adj, 3, 4);
    print_graph(adj, vertx);

    return 0;
}
