#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    double x;
    int ans=0;
    x=double(b)/double(m);
    if(m*a>=b){
        ans=(n/m)*b+min((n%m)*a,b);
    }
    else{
        ans=n*a;
    }
    cout<<ans;
}