//checking if directed graph is cyclic using dfs
#include<bits/stdc++.h>
using namespace std;
bool iscyclic(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(iscyclic(it,adj,vis,pathvis))return true;
        }
        else if(pathvis[it])return true;
    }
    pathvis[node]=0;
    return false;
}