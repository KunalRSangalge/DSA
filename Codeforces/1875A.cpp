#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long int ans=0;
        int temp=b;
        for(int i=0;i<n;i++){
            ans+=temp-1;
            temp=1;
            temp=min(a,1+arr[i]);
        }
        ans+=temp;
        cout<<ans<<endl;
    }
}
