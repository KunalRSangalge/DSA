#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int time=0;
    void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low, //time of insertion, lowest time reachable
            vector<vector<int>>&bridges,vector<vector<int>>&adj){
        vis[node]=1;
        tin[node]=low[node]=time; 
        time++;
        for(auto it : adj[node]){
            if(it==parent)continue; //avoid checking for parent node
            if(!vis[it]){ //if not visited adj node
                dfs(it,node,vis,tin,low,bridges,adj);
                low[node]=min(low[node],low[it]);
                if(tin[node]<low[it])bridges.push_back({it,node}); //if already visited just update low[node]
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        vector<int>tin(n),low(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0,-1,vis,tin,low,bridges,adj);
        return bridges;
    }
};