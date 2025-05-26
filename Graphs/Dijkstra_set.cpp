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
        vector<int>dist(V,1e9);
        set<pair<int,int>>st;
        st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int cur_dis = it.first;
            st.erase(it);
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(cur_dis+edgeWt < dist[adjNode]){
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                    dist[adjNode]=cur_dis+edgeWt;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
