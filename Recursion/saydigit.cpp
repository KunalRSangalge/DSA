#include<bits/stdc++.h>
using namespace std;

void dig(int n){
    if(n==0) { return ;}
    dig(n/10);
    int k=n%10;
    if(k==0)cout<<"Zero "; 
    if(k==1)cout<<"one "; 
    if(k==2)cout<<"two "; 
    if(k==3)cout<<"three "; 
    if(k==4)cout<<"four "; 
    if(k==5)cout<<"five "; 
    if(k==6)cout<<"six "; 
    if(k==7)cout<<"seven "; 
    if(k==8)cout<<"eight "; 
    if(k==9)cout<<"nine "; 
}
int main(){
    int n;
    cin>>n;
    dig(n);
}