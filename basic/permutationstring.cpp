#include<iostream>
#include<vector>
using namespace std;

void checks(vector<int>& freq1,string s1)
{
    for(int i=0;i<s1.length();i++){
        int x = s1[i] - 'a';
        freq1[x]++;
    }
    
}
int main()
{
    string s1="ab";
    string s2="eidbaooo";
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    checks(freq1,s1);

    int i=0,j=s1.length()-1;
    while(j<s2.length())
    {
        freq2.clear();

        for(int k=i;k<=j;k++){
            int x=s2[k]-'a';
            freq2[x]++;
        }
        

        if(freq1==freq2)
        {cout<<"yes";break;}

        else
        {i++;j++;}
    }
    cout<<s1[2];
    for(int i:freq1)
    cout<<freq1[i];
    cout<<endl;
    for(int i:freq2)
    cout<<freq2[i];
    cout<<"no";
}