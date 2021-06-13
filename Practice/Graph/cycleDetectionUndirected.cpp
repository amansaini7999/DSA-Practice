#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool isCyclic(vector<int> adj[], int s, int visited[], int parent){
    visited[s]=1;
    // cout<<s<<" ";

    for(auto itr: adj[s]){
        if(!visited[itr])
            if(isCyclic(adj, itr, visited, s))
                return true;

        else if(itr!=parent)
            return true;
    }

    return false;
}

int main(){
    int n=3;
    vector<int> adj[n];

    // addEdge(adj, 1, 0);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 2, 1);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 3, 4);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);

    int visited[n]={0};
    cout<<isCyclic(adj, 0, visited, -1)<<"\n";

    return 0;
}