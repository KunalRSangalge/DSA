#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1 | n==3){
            cout<<-1<<endl;
            continue;
        }
        string s="66";
        n-=2;
        if(n%2==0){
            while(n--){
                s+="3";
            }
        }
        else{
            s+="363";
            n-=3;
            while(n--){
                s+="3";
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;        
    }
}