#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans="hello";
    int j=0,k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==ans[j]){
            j++;
            k++;
        }
    }
    if(k==5) cout<<"YES";
    else cout<<"NO";

}

