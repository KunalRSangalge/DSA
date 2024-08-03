#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<"enter char "<<endl;
    char ch[n];
    for(int i=0;i<n;i++){
        cin>>ch[i];
    }

    //precomputation
    int hash[26]={0};
    for(int i=0;i<n;i++){
        hash[ch[i]-'a']++;
    }

    //test case and output
    int t;
    cin>>t;
    while(t--){
        char c;
        cin>>c; // to find
        cout<<hash[c-'a']<<" ";
    }

}