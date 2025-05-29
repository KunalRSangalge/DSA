#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>parent,size;
  public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(parent[node]==node)return node;
        return parent[node]=find_parent(parent[node]);
    }
    void union_by_size(int u,int v){
        int pu = find_parent(u), pv = find_parent(v);
        if(pu==pv)return;
        if(size[pu] > size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        DSU ds(V);
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt,{i,adjNode}});
            }
        }
        sort(edges.begin(),edges.end());
        int ans=0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i].second.first, v = edges[i].second.second , wt = edges[i].first;
            if(ds.find_parent(u)!=ds.find_parent(v)){
                ans+=wt;
                ds.union_by_size(u,v);
            }
        }
        return ans;
    }
};