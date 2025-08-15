#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int n = k*2;
        cout<<n<<endl;
        long long x=0,y1=0,y2=1;
        for(int i=0;i<k;i++){
            cout<<x<<" "<<y1<<endl;
            cout<<x<<" "<<y2<<endl;
            x+=2;
            y1+=2;
            y2+=2;
        }        
    }
}