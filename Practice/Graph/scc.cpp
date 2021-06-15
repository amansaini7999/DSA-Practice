#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
}

void dfsTopo(vector<int> adj[], int node, vector<int>& vis, stack<int>& st){
    vis[node]=1;

    for(auto itr: adj[node])
        if(!vis[itr])
            dfsTopo(adj, itr, vis, st);
    
    st.push(node);
}

void dfs(vector<int> adj[], int node, vector<int>& vis){
    cout<<node<<" ";
    vis[node]=1;

    for(auto itr: adj[node]){
        if(!vis[itr])
            dfs(adj, itr, vis);
    }
}

int main(){

    int n=5;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    stack<int> st;
    vector<int> vis(n);
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfsTopo(adj, i, vis, st);
    }

    vector<int> aux[n];
    for(int i=0; i<n; i++){
        vis[i]=0;
        for(auto itr: adj[i])
            aux[itr].push_back(i);
    }

    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            dfs(aux, top, vis);
            cout<<"\n";
        }
    }

    return 0;
}