#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool checkBipartite(vector<int> adj[], int node, vector<int>& colour){
    if(colour[node]==-1)
        colour[node]=1;
    
    for(auto itr: adj[node]){
        if(colour[itr]==-1){
            colour[itr]=1-colour[node];

            if(!checkBipartite(adj, itr, colour))
                return false;
        }
        else if(colour[itr]==colour[node])
            return false;
    }
    return true;
}

int main(){
    int n=5;
    vector<int> adj[n];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 1);

    int flag=0;
    vector<int> colour(n);

    for(int i=0; i<n; i++)
        colour[i]=-1;
    
    for(int i=1; i<5; i++){
        if(colour[i]==-1)
            if(checkBipartite(adj, i, colour))
               flag=1;
    }

    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}