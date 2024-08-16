#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    string ans="";
    for(int i=0;i<26;i++){
        if(freq[i]%k!=0) {cout<<-1;
        return 0;}
        else {
            for(int j=0;j<freq[i]/k;j++){
                ans+=(i+'a');
            }
        }
    }
    for(int i=0;i<k;i++) cout<<ans;
}