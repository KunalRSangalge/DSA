#include<bits/stdc++.h>
using namespace std;
class Solution1 {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<pair<int,int>>>&adj) {
        int sum = 0;
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
            greater<pair<int,int>>>pq; //{dist,node}
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            sum+=wt;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeWt,adjNode});
                }
            }
        }
        return sum;
    }
};
class Solution {
  public:
    // Function to find sum of weights and the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<pair<int,int>>> adj) {
        vector<vector<int>>MST(V);
        int sum = 0;
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; //{distance,{node,parent}
        vector<int>vis(V,0);
        pq.push({0,{0,-1}});
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            sum+=dist;
            if(parent!=-1){
                MST[parent].push_back(node);
                MST[node].push_back(parent);
            }
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeWt,{adjNode,node}});
                }
            }
        }
        return sum;
    }
};