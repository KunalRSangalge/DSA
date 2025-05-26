#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        while(!q.empty()){
            int node = q.front().first;
            int cur_dis = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(cur_dis+1 < dist[it]){
                    dist[it]=cur_dis+1;
                    q.push({it,dist[it]});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};