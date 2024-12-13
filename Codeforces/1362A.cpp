    #include<bits/stdc++.h>
    #define ll long long int
    #define N 1e9
    using namespace std;
    vector<bool>prime(N+1,true);
    // O(NloglogN) sieve of erastosthanes
    void p(){
        prime[0]=false;
        prime[1]=false;
        for(ll i=0;i<N;i++){
            if(prime[i]){
                for(ll j=2*i;j<N;j+=i){
                    prime[j]=false;
                }
            }
        }
    }
    vector<ll> div(ll n){
        vector<ll>div;
        for(ll i=1;i<=sqrt(n);i++){
            if(n%i==0){
                div.push_back(i);
                div.push_back(n/i);
            }
        }
        return div;
    }
    void yes(){
        cout<<"YES"<<endl;
    }
    void no(){
        cout<<"NO"<<endl;
    }
    ll getpow(ll n){
        ll ans=0;
        while(n>1){
            if(n%2!=0) return 0;
            n/=2;
            ans++;
        }
        return ans;
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            ll a,b;
            ll n;
            cin>>a>>b;
            if(a==b){
                cout<<0<<endl;
                continue;
            }
            else if(a>b && a%b==0){
                n=a/b;
            }
            else if(b>a  && b%a==0){
                n=b/a;
            }
            else{
                cout<<-1<<endl;
                continue;
            }

            if(getpow(n)){
                ll x = getpow(n);
                double ans = x/3.0;
                cout<<ceil(ans)<<endl;
            }
            else cout<<-1<<endl;
        }
    }