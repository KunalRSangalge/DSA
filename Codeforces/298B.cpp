#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,sx,sy,ex,ey;
    string a;
    cin>>t>>sx>>sy>>ex>>ey;
    cin>>a;

    int ans=0;
    for(int i=0;i<t;i++){
        if(sx==ex && sy==ey){
            cout<<ans;
            exit(0);
        }

        //for x
        if(sx!=ex){
            if(sx>ex){
                if(a[i]=='W'){
                    sx--;
                    ans++;
                    continue;
                }                
            }
            else{
                if(a[i]=='E'){
                    sx++;
                    ans++;
                    continue;
                }
            }
        }

        //for y
        if(sy!=ey){
            if(sy>ey){
                if(a[i]=='S'){
                sy--;
                ans++;
                continue;
            }
            }
            else{
                if(a[i]=='N'){
                sy++;
                ans++;
                continue;
            }
            }
        }
        ans++;
    }
    if(sx==ex && sy==ey){
            cout<<ans;
            exit(0);
    }
    if(sx!=ex || sy!=ey)cout<<"-1";
}