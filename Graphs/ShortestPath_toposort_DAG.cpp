#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void topo_dfs(int i, vector<int>&vis,vector<vector<pair<int,int>>>adj,stack<int>&st){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it.first]){
                topo_dfs(it.first,vis,adj,st);
            }
        }
        st.push(i);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>dist(V,1e9);
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            topo_dfs(i,vis,adj,st);
        }
        
        // while(st.top()!=0)st.pop(); --> can skip the rest of the stack and start directle from source
        
        dist[0]=0;
        while(!st.empty()){
            int node = st.top();
            int cur_dis = dist[node];
            st.pop();
            for(auto it : adj[node]){
                if(cur_dis+it.second < dist[it.first]){
                    dist[it.first]=cur_dis+it.second;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};
