#include<bits/stdc++.h>
using namespace std;

int N=1000000;
bool sieve[1000001];
void createSieve(){
    for(int i=2;i<N;i++)
    sieve[i]=true;

    for(int i=2;i*i<N;i++){
        if(sieve[i]){
            for(int j=i*i;j<=N;j++)
            sieve[j]=false;
        }
    }
}
vector<int> prime(int n){
    vector<int>p;
    for(int i=2;i<=n;i++){
        if(sieve[i])
        p.push_back(i);
    }
    return p;
}
int main(){
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        //generating all primes upto sqrt(R)
        vector<int> primes = prime(sqrt(r));

        //creating dummy array of size r-l+1 and make 1
        int dummy[r-l+1];
        for(int i=0;i<(r-l+1);i++)
        dummy[i]=1; 

        //mark all multiples of prime on dummy as false
        for(auto pr: primes){

            int firstmultiple = (l/pr)*pr;
            if(firstmultiple<l) firstmultiple+=pr; //l/pr -> integer and *pr will give first multiple

            for(int j=max(firstmultiple,pr*pr);j<=r;j+=pr){
                dummy[r-l]=false;
            }
        }

        //get all primes
        for(int i=l;i<=r;i++){
            if(dummy[i])
            cout<<i<<' ';            
        }
    }
}