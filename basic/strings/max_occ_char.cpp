#include<iostream>
using namespace std;

int maxi(int a[])
{
    int max=INT16_MIN,t;
    for(int i=0;i<26;i++)
    {
        if(a[i]>max)
        {max=a[i];t=i;}
    }
    return t;    
}
char Maxocc(string s)
{
    int freq[26];
    for(int i=0;i<26;i++)freq[i]=0;

    for(int i=0;i<s.length();i++)
    freq[s[i]-97]++;

    int t=maxi(freq);
    char ch=t+97;

    return ch;
}

int main()
{
    cout<<"enter string"<<endl;
    string s;
    cin>>s;

    cout<<"Max occuring letter: "<<Maxocc(s);
}