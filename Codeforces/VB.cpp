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
        ll x=0,y=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                y++;
                if(x==1 && y==1){
                    flag=true;
                    break;
                }
            }
            if(s[i]=='D'){
                y--;
                if(x==1 && y==1){
                    flag=true;
                    break;
                }
            }
            if(s[i]=='L'){
                x--;
                if(x==1 && y==1){
                    flag=true;
                    break;
                }
            }
            if(s[i]=='R'){
                x++;
                if(x==1 && y==1){
                    flag=true;
                    break;
                }
            }
        }
        
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}