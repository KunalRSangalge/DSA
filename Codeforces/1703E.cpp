#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define mp make_pair
#define vpii vector<pair<int, int>>
#define vll vector<ll>
#define vc vector<char>
#define mii map<int, int>
#define mll map<ll, ll>
#define mil map<int, ll>
#define mli map<ll, int>
#define mci map<char, int>
#define mic map<int, char>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<vector<int>> a(n , vi(n));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        char ch;
        cin>>ch;
        a[i][j] = ch-'0';
      }
    }
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int s = a[i][j] + a[j][n-1-i] + a[n-1-i][n-1-j] + a[n-1-j][i];
        ans+=min(s,4-s);
      }
    }
    cout<<ans/4<<'\n';
  }
}