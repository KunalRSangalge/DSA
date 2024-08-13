//A:question , 1:Question number ,-2: level
#include<bits/stdc++.h>
using namespace std;
bool vowel(char ch){
    if(ch=='a' || ch=='e' ||  ch=='i'|| ch=='o'|| ch=='y'|| ch=='u')
    return true;
    return false;
}
void tolow(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
}

int main(){
    string s;
    cin>>s;
    string ans="";
    tolow(s);
    for(int i=0;i<s.size();i++){
        if(!vowel(s[i])){
            ans+=".";
            ans+=s[i];
        }
    }
    // for(int i=0;i<ans.size();i++) cout<<ans[i];
    cout<<ans;
}