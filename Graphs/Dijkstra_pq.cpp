#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        dist[src]=0;
        pq.push({0,src}); // pq has {dist,node}
        while(!pq.empty()){
            int cur_dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(cur_dis+adjWt < dist[adjNode]){
                    dist[adjNode]=cur_dis+adjWt;
                    pq.push({dist[adjNode],adjNode}); 
                }
            }
        }
        return dist;
    }
};
