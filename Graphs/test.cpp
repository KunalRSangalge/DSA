#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int time,vector<int>&tin,vector<int>&low,vector<vector<int>>&adj,vector<int>&vis,vector<pair<int,int>>bridges){
    vis[node]=1;
    tin[node]=low[node]=time;
    time++;
    for(auto it : adj[node]){
        if(it==parent)continue;
        if(!vis[it]){
            dfs(it,node,time,tin,low,adj,vis,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node])bridges.push_back({it,node});
        }else{
            low[node]=min(low[node],low[it]);
        }
    }
}