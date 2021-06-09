#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void dfs(vector<int> adj[], int start, int visited[]){
    visited[start]=1;
    cout<<start<<" ";

    for(auto itr: adj[start])
        if(!visited[itr])
            dfs(adj, itr, visited);
}

void bfs(vector<int> adj[], int start, int visited[]){
    queue<int> helperQueue;
    helperQueue.push(start);
    visited[start]=1;

    while(!helperQueue.empty()){
        start = helperQueue.front();
        cout<<start<<" ";
        helperQueue.pop();

        for(auto itr: adj[start]){
            if(!visited[itr]){
                helperQueue.push(itr);
                visited[itr]=1;
            }
        }
    }
}

void print(vector<int> adj[]){
    for(int i=0; i<5; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 0, 4);
    addEdge(adj, 1, 4);

    int visited[5] = {0};
    cout<<"DFS: ";
    dfs(adj, 0, visited);

    int visit[5] = {0};
    cout<<"\nBFS: ";
    bfs(adj, 0, visit);

    cout<<"\n\n";

    print(adj);
    return 0;
}