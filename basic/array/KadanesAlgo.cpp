//finding max sum subarray in array
//finds only the sum in -> O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[9]={-2,1,-3,4,-1,2,1,-5,4};

    int sum=0,maxi=a[0];
    for(int i=0;i<9;i++){
        sum+=a[i];
        if(sum>maxi) maxi = sum;
        if(sum<0) sum = 0;
    }

    cout << "max sum = "<<maxi;
}