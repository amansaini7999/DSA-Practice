#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
}

bool isCyclic(vector<int> adj[], int s, int visited[], int dfsVisited[]){
    visited[s]=1;
    dfsVisited[s]=1;

    for(auto itr: adj[s]){
        if(!visited[itr]){
            if(isCyclic(adj, itr, visited, dfsVisited))
                return true;
        }
            
        else if(dfsVisited[itr])
            return true;
    }

    dfsVisited[s]=0;
    return false;
}

int main(){
    vector<int> adj[5];

    addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);

    int visited[5]={0};
    int dfsVisited[5]={0};
    int flag=0;
    for(int i=0; i<=2; i++){
        if(!visited[i]){
            if(isCyclic(adj, i, visited, dfsVisited)){
                flag=1;
                break;
            }
        }
    } 

    if(flag==1)
        cout<<"Yes"<<"\n";
    else
        cout<<"No\n";

    return 0;
}