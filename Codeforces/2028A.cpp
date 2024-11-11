#include<bits/stdc++.h>
#define ll long long int
#define check 1000
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        ll i=0,j=0,k=0;
        bool flag=false;
        while(i<check && i>(-check) && j<check && j>(-check)){
            if(i==a && j==b){
                flag=true;
                break;
            }
            if(s[k]=='N'){
                j++;
            }
            if(s[k]=='S'){
                j--;
            }
            if(s[k]=='E'){
                i++;
            }
            if(s[k]=='W'){
                i--;
            }
            k++;
            
            if(k==n){
                if(i==0 && j==0){
                    flag = false;
                    break;
                }
                else k=0;
            }
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}