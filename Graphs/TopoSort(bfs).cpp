//Kahns algorithm same TC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int V;
    vector<vector<int>>adj(V);
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
}