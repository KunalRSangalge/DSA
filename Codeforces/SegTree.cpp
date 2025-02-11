#include<bits/stdc++.h>
using namespace std;
#define ll long long
//NOTE: 0-based indexing
class SGTree{   
    public: 
        vector<ll>seg;
        SGTree(ll n){
            seg.resize(4*n+1);
        }
        void build(ll ind,ll low,ll high,ll arr[]){
            if(low==high){
                seg[ind]=arr[low];
                return;
            }
            ll mid = (high+low)/2;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        }

        ll query(ll ind,ll low, ll high,ll l,ll r){
            //no overlap -> l r low high or low high l r
            if(r<low || high<l){
                return INT_MAX;
            }
            //complete overlap -> l low high r
            if(low>=l && high<=r){
                return seg[ind];
            }
            // partial overlap
            ll mid = (low+high)/2;
            ll left = query(2*ind+1,low,mid,l,r);
            ll right = query(2*ind+2,mid+1,high,l,r);
            return min(left,right);
        }

        void update(ll ind,ll low,ll high,ll i,ll val){
            if(low==high){
                seg[ind]=val;
                return;
            }
            ll mid = (high+low)/2;

            if(i<=mid){
                update(2*ind+1,low,mid,i,val);
            }
            else{
                update(2*ind+2,mid+1,high,i,val);
            }

            seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        }
};

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    SGTree seg1(n);
    seg1.build(0,0,n-1,a);
    cout<<seg1.query(0,0,n-1,2,4);
    seg1.update(0,0,n-1,2,-1);
    cout<<seg1.query(0,0,n-1,2,4);
}