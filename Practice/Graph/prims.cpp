#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int i, int j, int wt){
    adj[i].push_back(make_pair(j, wt));
    adj[j].push_back(make_pair(i, wt));
}

int main(){
    int n=5;
    vector<pair<int, int>> adj[n];

    addEdge(adj, 0, 1, 3);
    addEdge(adj, 1, 2, 4);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 3, 4, 3);
    addEdge(adj, 4, 0, 7);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> vis(n, 0);
    vector<int> weights(n, 0);

    pq.push(make_pair(0, 0));
    for(int i=0; i<n; i++){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        vis[node]=1;
        weights[node]=it.first;
        cout<<node<<" ";

        for(auto itr: adj[node]){
            if(!vis[itr.first])
                pq.push(make_pair(itr.second, itr.first));
        }
    }

    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<weights[i]<<" ";
    cout<<"\n";

    return 0;
}