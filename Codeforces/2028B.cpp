#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,b,c;
        cin>>n>>b>>c;
        if(b==0){
            if(c>=n-2){
                if(c<=n-1) cout<<n-1<<endl;
                else cout<<n<<endl;
            }
            else cout<<-1<<endl;
            continue;
        }
        ll ans=0;
        if(c<n){
            ans+=((n-1-c)/b);
            ans++;
        }
        cout<<n-ans<<endl;
    }
}