#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>& a, 
        pair<int, int>& b) 
{ 
    return a.second > b.second; 
} 
 
void sort(map<int, int>& M) 
{ 
    vector<pair<int, int> > A; 
 
    for (auto& it : M) { 
        A.push_back(it); 
    } 

    sort(A.begin(), A.end(), cmp); 
} 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int b[n],c[n];
        for(int i=0;i<k;i++){
            cin>>b[i]>>c[i];
        }
        map<int,int>mpp;
        for(int i=0;i<k;i++){
            mpp[b[i]]+=c[i];
        }
        sort(mpp);
        int count=0;
        for(auto x : mpp){
                count++;
        }
        int ans=0;
        if(n>=count){
            for(auto x : mpp){
                ans+=x.second;
            }
            cout<<ans<<endl;
        }
        else{
            for(auto x : mpp){
                if(n<=0)break;
                ans += x.second;
                n--;
            }
            cout<<ans<<endl;
        }
    }
}