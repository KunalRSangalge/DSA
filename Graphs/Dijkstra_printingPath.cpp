#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1,0);
        for(int i=1;i<=n;i++)parent[i]=i;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[1]=0;
        pq.push({0,1}); // pq has {dist,node}
        while(!pq.empty()){
            int cur_dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(cur_dis+adjWt < dist[adjNode]){
                    dist[adjNode]=cur_dis+adjWt;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode}); 
                }
            }
        }
        
        if(dist[n]==1e9)return {-1};
        
        int cur = n;
        vector<int>ans;
        while(parent[cur]!=cur){
            ans.push_back(cur);
            cur=parent[cur];
        }
        ans.push_back(cur);
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        // for(auto it : ans)cout<<it<<" ";cout<<endl;
        return ans;
    }
};