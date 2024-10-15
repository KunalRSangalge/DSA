#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,xk,xq,yk,yq;
        cin>>a>>b;
        cin>>xk>>yk;
        cin>>xq>>yq;
        int ans=0;
        bool flag=false;
        //case 1: +-
        int x,y;
        x=xk+a;
        y=yk-b;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        //case2 : -+
        x=xk-a;
        y=yk+b;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        //case3 : ++
        x=xk+a;
        y=yk+b;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        //case 4:--
        x=xk-a;
        y=yk-b;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        if(a!=b){
            //case5: +-
        x=xk+b;
        y=yk-a;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        //case6: -+
        x=xk-b;
        y=yk+a;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        //case7: ++
        x=xk+b;
        y=yk+a;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;
        
        //case8: --
        x=xk-b;
        y=yk-a;
        if(x+a==xq && y+b==yq) flag=true;
        if(x+a==xq && y-b==yq) flag=true;
        if(x-a==xq && y+b==yq) flag=true;
        if(x-a==xq && y-b==yq) flag=true;
        if(x+b==xq && y+a==yq) flag=true;
        if(x+b==xq && y-a==yq) flag=true;
        if(x-b==xq && y+a==yq) flag=true;
        if(x-b==xq && y-a==yq) flag=true;
        if(flag==true) ans++;
        flag=false;

        }

        cout<<ans<<endl;
    }
}

