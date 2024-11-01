#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        long long int ans=n;
        int i=0;
        while(i<n){
            if(a[i]=(ans+1-i)){
                ans+=(i-1);
                i=0;
            }
            else{
                i++;
            }
        }
        cout<<ans<<endl;
    }
}