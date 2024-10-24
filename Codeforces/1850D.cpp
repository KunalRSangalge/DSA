//TLE
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int i=0,j=1;
        int ans=0,count=1;
        while(i<n && j<n){
            if(arr[j]- arr[i]  <= k){
                count++;
                i++;
                j++;
            }
            else{
                ans=max(ans,count);
                i++;
                j++;
                count=1;
            }
        }  
        ans=max(ans,count);
        cout<<n-ans<<endl; 
    }
}