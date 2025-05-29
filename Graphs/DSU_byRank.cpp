#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>parent,rank;
  public:
    DSU(int n){
        parent.resize(n+1,0); //1-based indexing
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(parent[node]==node)return node;
        return parent[node]=find_parent(parent[node]); //path compression
    }
    void union_by_rank(int u,int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv)return; //in same component
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main(){
    DSU dsu(7);
    dsu.union_by_rank(1,2);
    dsu.union_by_rank(2,3);
    dsu.union_by_rank(4,5);
    dsu.union_by_rank(6,7);
    dsu.union_by_rank(5,6);
    if(dsu.find_parent(7)==dsu.find_parent(3)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
    dsu.union_by_rank(3,7);
    if(dsu.find_parent(7)==dsu.find_parent(3)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
}