#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lis(vector<ll>&arr,int n){
    vector<ll>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > temp.back())temp.push_back(arr[i]);
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind]=arr[i];
        }
    }
    return temp.size();
}
int main(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<lis(arr,n);
}