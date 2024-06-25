#include<iostream>
#include<vector>
using namespace std;

vector<char> s;
void add(vector<char>& ch,vector<char>& s,int i,int j){
    while(i<=j)
    {
        s.push_back(ch[i]);
        i++;
    }
}

void revword(vector<char>& ch){
    
    int n=ch.size();
    int i=n-1,j=n-1;
    while(i>=0)
    {
        while(i>=0 && ch[i]!=' ')i--;
        add(ch,s,i+1,j);
        if(!s.empty())s.push_back(' ');
        while(i>=0 && ch[i]==' ')i--;
        j=i;                
    }

}
int main(){
    vector<char> ch;
    ch.push_back('s');
    ch.push_back('k');
    ch.push_back('y');
    ch.push_back(' ');
    ch.push_back(' ');
    ch.push_back('i');
    ch.push_back('s');
    ch.push_back(' ');
    ch.push_back('b');
    ch.push_back('l');
    ch.push_back('u');
    ch.push_back('e');
    
    for(int i=0;i<ch.size();i++)
    cout<<ch[i];

    cout<<endl;
    revword(ch);

    for(int i=0;i<s.size();i++)
    cout<<s[i];
}