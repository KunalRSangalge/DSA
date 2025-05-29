#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int timer = 0;
    void dfs(int node,int parent,vector<int>&vis,vector<int> &tin,vector<int>&low,
             vector<int>&mark,vector<int>adj[]){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1)mark[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        int n = V;
        vector<int>vis(V,0),tin(n),low(n),mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mark[i])ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};