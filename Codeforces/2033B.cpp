#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p,q;
                int x=i,y=j;
                if(a[i][j]<0){
                    int mini=INT_MAX;
                    while(x<n && y<n){
                        if(a[x][y]<0){
                            if(a[x][y]<mini){
                                p=x;
                                q=y;
                                mini=a[x][y];
                            }
                        }
                        x++; y++;
                    }
                    int k = abs(a[p][q]);
                    ans+=k;
                    int r=i,t=j;
                    while(r<n && t<n){
                        a[r][t]+=k;
                        r++; t++;
                    }
                    
                }
            }
        }
        cout<<ans<<endl;
    }
}