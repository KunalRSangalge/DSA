#include<bits/stdc++.h>
using namespace std;
int check(int n,int i){
    if(n==pow(10,i)){
            return 9*i+1;        
    }
    else{
        if(i==1) return n;
        return 9*(i-1)+(n/pow(10,i-1));
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<8;i++){
            if(n<=pow(10,i)){
                ans=check(n,i);
                break;
            }
        }
        cout<<ans<<endl;
    }
}