//counting the number of subsequence givin sum k
//important Algo

#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int idx,int sum, int k){
    if(idx>=3){
        if(sum==k){
            return 1;
        }        
        return 0;
    }
    //include
    sum+=arr[idx];
    int l = solve(arr,idx+1,sum,k);

    sum-=arr[idx];

    //exclude
    int r = solve(arr,idx+1,sum,k);

    return l+r;
}
int main(){
    int arr[3]= {1,2,1};
    int idx=0,sum=0,k=4;
    cout<<solve(arr,idx,sum,k);
}