#include<bits/stdc++.h>
#include<string>
using namespace std;
bool check(string s, int n){
    if(n<4)return false;

    for(int i=0;i<=n-4;i++){
        if(s.substr(i,4)=="1100"){
            return true;
        }
    }
    return false;
}  

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n;
        cin>>n;
        int a[n],p[n];
        for(int i=0;i<n;i++){
            cin>>p[i]>>a[i];
        }
        int i=0;
        string temp = s;
        while(n--){     
            char c;
            if(a[i]==1){
                c='1';
            }
            else{
                c='0';
            }
            temp[p[i]-1]=c;
            i++;
            if(check(temp,s.length()))cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }

    }
}