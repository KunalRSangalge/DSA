#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>parent,size;
  public:
    DSU(int n){
        parent.resize(n+1,0); //1-based indexing
        size.resize(n+1,1); 
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(parent[node]==node)return node;
        return parent[node]=find_parent(parent[node]); //path compression
    }
    void union_by_size(int u,int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv)return; //same component
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main(){
    DSU dsu(7);
    dsu.union_by_size(1,2);
    dsu.union_by_size(2,3);
    dsu.union_by_size(4,5);
    dsu.union_by_size(6,7);
    dsu.union_by_size(5,6);
    if(dsu.find_parent(7)==dsu.find_parent(3)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
    dsu.union_by_size(3,7);
    if(dsu.find_parent(7)==dsu.find_parent(3)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
}