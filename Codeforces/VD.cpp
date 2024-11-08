#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char,ll>mpp;
        map<char,ll>mpp2;

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

        ll ans = mpp.size();
        for(int i=0;i<n-1;i++){
            mpp2[s[i]]++;
            mpp[s[i]]--;
            if(mpp[s[i]]==0) mpp.erase(s[i]);
            ll temp = (mpp2.size()+mpp.size());
            ans = max(ans,temp);
            
        }
        cout<<ans<<endl;
    }
}