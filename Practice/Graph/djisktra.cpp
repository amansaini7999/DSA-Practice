#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int i, int j, int wt){
    adj[i].push_back(make_pair(j, wt));
    adj[j].push_back(make_pair(i, wt));
}

int main(){
    int n=6;
    vector<pair<int, int>> adj[n];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 1, 2, 7);
    addEdge(adj, 2, 5, 1);
    addEdge(adj, 0, 3, 9);
    addEdge(adj, 3, 4, 1);
    addEdge(adj, 4, 5, 1);

    priority_queue<pair<int, int>,vector<pair<int, int>> , greater<pair<int, int>>> pq;
    vector<int> dis(n, INT_MAX);

    int source=0;
    dis[source]=0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto itr: adj[prev]){
            int next = itr.first;
            int nextDist = itr.second;

            if(dis[next] > dis[prev]+nextDist){
                dis[next] = dis[prev]+nextDist;
                pq.push(make_pair(dis[next], next));
            }
        }
    }

    for(auto itr: dis){
        cout<<itr<<" ";
    }
    cout<<"\n";

    return 0;
}