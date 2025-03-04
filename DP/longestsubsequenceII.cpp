//dp on strings
//printing the longest subsequence of strings
#include<bits/stdc++.h>
using namespace std;
void longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int len = dp[n][m];
        string ans = "";
        for(int i=0;i<len;i++) ans+='&';

        int ind = len-1;
        int i=n,j=m;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans[ind]=text1[i-1];
                ind--;
                i-=1;
                j-=1;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        cout<<ans;
    }
int main(){
    string s1 = "abcde";
    string s2 = "bdgek";
    longestCommonSubsequence(s1,s2);
}