#include<iostream>
#include<vector>
using namespace std;
int digits(int n)
    {
        int digit=0,i=0,temp=n;
        while(temp!=0)
        {
            temp/=10;
            digit++;
        }
        return digit;
         
    }
int compress(vector<char>& chars) {
           char ch;
        int i=0,count[26]={0};
        while(i<chars.size())
        {
            ch=chars[i];
            int x = ch -'a';
            count[x]++;
            i++;            
        }
        
        int j=0;
        for(int i=0;i<26;i++)
        {
            if(count[i]>0)
            {
                ch = i + 'a';
                chars[j]=ch;

                if(count[i]!=1 && count[i]<10)
                {chars[j+1]=count[i]+48;j+=2;}
                else if(count[i]>=10)
                {
                    int x=digits(count[i]);
                    int t=x;
                    int y=count[i];
                    while(x!=0)
                    {                        
                        chars[j+x]=(y%10) + 48;
                        y/=10;
                        x--;
                    }
                    j+=t+1;
                }
                else
                j++;
            }
            
        }
        int t=j;
        for(int i=j;i<chars.size();i++)
        {
            chars[i]='\0';
        }
        return j;
    }
int main()
{
    vector<char> chars{'a','a','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c'};
    cout<<compress(chars);
    
    for(int i=0;i<chars.size();i++)
    cout<<chars[i]<<' ';
}