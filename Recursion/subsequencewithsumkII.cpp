//printing only one of the subsequence -> pne way is to put flag but here we will do functionally
//In first part we printed all the subsequences
#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[],vector<int>&ds,int idx,int sum, int k){
    if(idx>=3){
        if(sum==k){
            for(auto it : ds)
            cout<<it<<" ";
            cout<<endl;
            return true;
        }        
        return false;
    }
    //include
    sum+=arr[idx];
    ds.push_back(arr[idx]);
    if(solve(arr,ds,idx+1,sum,k)) return true;

    sum-=arr[idx];
    ds.pop_back();

    //exclude
    if(solve(arr,ds,idx+1,sum,k)) return true;

    return false;
}
int main(){
    int arr[3]= {1,2,1};
    vector<int> ds;
    int idx=0,sum=0,k=2;
    solve(arr,ds,idx,sum,k);
}