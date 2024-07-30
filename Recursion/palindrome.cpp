#include<bits/stdc++.h>
using namespace std;

bool pal(string s, int n, int m){
    if(n>=m) return true;

    if(s[n]!=s[m])return false;

    return pal(s,n+1,m-1);
}
int main(){
    string s="racecar";
    string ans="";
    cout<<pal(s,0,6);
}