#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dis(V,1e8);
        dis[src]=0;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if(dis[u]!=1e8 && dis[u]+wt < dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        for(int j=0;j<edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dis[u]!=1e8 && dis[u]+wt < dis[v])return {-1};
        }
        return dis;
    }
};
