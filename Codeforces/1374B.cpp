#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        if(n==1) {cout<<"0"<<endl;continue;}

        int d2=0,d3=0;
        int t=n;
        while(t%2==0){
            d2++;
            t/=2;
        }
        t=n;
        while(t%3==0){
            d3++;
            t/=3;
        }
        int check = (pow(2,d2)*pow(3,d3));
        if(check==n && d3>=d2){
            cout<<(d3-d2)+d3<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}