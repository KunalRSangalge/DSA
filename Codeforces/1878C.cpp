#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
      /*  long long n,k,x;
        cin>>n>>k>>x;
        long long ans1=0;
        long long ans2=0;
        long long ans=0;
        ans=(k*(2*n-k+1))/2;
        ans2=((n)*(n+1))/2;
        ans1=((k)*(k+1))/2;
        if(ans1 > x) cout<<"NO"<<endl;
        else if(ans2 < x) cout<<"NO"<<endl;
        else if( ans < x)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;*/
        ll a,b,n;
        cin>>a>>b>>n;
        vector<ll>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(b-1);
            b=1;
            b=min(a,b+arr[i]);


        }
        ans+=b;
        cout<<ans<<endl;

    }
}