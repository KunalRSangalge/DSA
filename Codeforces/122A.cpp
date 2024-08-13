#include<bits/stdc++.h>
using namespace std;
bool lucky(int n){
    //full lucky
    bool flag = true;
    int temp=n;
    while(temp){
        int rem = temp%10;
        if(rem == 4 || rem == 7) {flag=true;}
        else{flag = false; break;}
        temp/=10;
    }
    return flag;
}
int main(){
    int n;
    cin>>n;
    int check[14]={4,7,44,77,47,74,444,777,447,474,744,774,747,477};
    bool flag=false;
    if(lucky(n)){
        cout<<"YES";
    }
    else{
        for(int i=0;i<14;i++){
            if(n%check[i]==0){
            flag=true;
            break;
            }
        }
        if(flag)cout<<"YES";
        else cout<<"NO";
    }
    
}