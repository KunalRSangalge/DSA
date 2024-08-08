#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],vector<int>&ds,int idx,int sum, int k){
    if(idx>=3){
        if(sum==k){
            for(auto it : ds)
            cout<<it<<" ";
            cout<<endl;
        }        
        return ;
    }
    //include
    sum+=arr[idx];
    ds.push_back(arr[idx]);
    solve(arr,ds,idx+1,sum,k);

    sum-=arr[idx];
    ds.pop_back();

    //exclude
    solve(arr,ds,idx+1,sum,k);

}
int main(){
    int arr[3]= {1,2,1};
    vector<int> ds;
    int idx=0,sum=0,k=2;
    solve(arr,ds,idx,sum,k);
}