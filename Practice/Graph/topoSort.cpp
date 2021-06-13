#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
}

void topoSort(vector<int> adj[], int node, vector<int>& visited, stack<int>& ans){
    visited[node]=1;

    for(auto itr: adj[node]){
        if(!visited[itr])
            topoSort(adj, itr, visited, ans);
    }

    ans.push(node);
}

int main(){
    int n=6;
    vector<int> adj[n];

    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    vector<int> visited(n, 0);
    stack<int> ans;

    for(int i=0; i<n; i++){
        if(!visited[i])
            topoSort(adj, i, visited, ans);
    }

    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

    return 0;
}