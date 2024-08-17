#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,n;
    cin>>s>>n;
    int x,y;
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        p.push_back(make_pair(x,y));
    }
    sort(p.begin(),p.end());
    bool flag=true;
    for(int i=0;i<n;i++){
        if(s>p[i].first){
            s+=p[i].second;
        }
        else {
            flag=false;
            break;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
}