#include<bits/stdc++.h> 
using namespace std;
int main(){
    //input of arr
    int n;
    cin>>n;
    cout<<"enter ele"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    //precomputation 
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    //output for every test case
    int t;
    cin>>t;
    int number; // to find
    while(t--){
        cin>>number;
        cout<<mpp[number]<<" ";
    }
}