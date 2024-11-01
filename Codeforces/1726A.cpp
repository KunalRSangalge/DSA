#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mini=INT_MAX, maxi=INT_MIN;
        int x,y;
        for(int i=0;i<n;i++){
            if(a[i]<mini){
                mini=a[i];
                x=i;
            }
            if(a[i]>maxi){
                maxi=a[i];
                y=i;
            }
        }
        int ans=-1;
        if(a[0]==mini || a[n-1]==maxi ){
            ans=maxi-mini;
        }
        else{
            ans=max(ans,maxi-a[0]);
            ans=max(ans,a[n-1]-mini);

            for(int i=0;i<n-1;i++){
                ans=max(ans,(a[i]-a[i+1]));

            }
            
        }
        cout<<ans<<endl;
    }
}