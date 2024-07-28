#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);
    p.push_back(14);
    p.push_back(5);

    vector<int>::iterator it=p.begin();
    it++;
    cout<<*(it)<<" ";

    for(vector<int>::iterator itt=p.begin();it!=p.end();it++){
        cout<<*(it)<<endl;
    }
}