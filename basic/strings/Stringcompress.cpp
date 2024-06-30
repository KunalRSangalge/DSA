#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
            int i = 0, j = 0, n = chars.size(), ansIndex = 0;
        char ch;
        while (i < n && j < n)
            
        {
            j = i + 1;
            while (j < n && chars[i] == chars[j])
                j++;

            chars[ansIndex++] = chars[i];
            int count = j - i;

            if (count > 1) {
                string str = to_string(count);
                for (char ch : str)
                    chars[ansIndex++] = ch;
            }

            i = j;
        }
        return ansIndex;
    }
int main()
{
    vector<char> chars{'a','a','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c'};
    cout<<compress(chars);
    
    for(int i=0;i<chars.size();i++)
    cout<<chars[i]<<' ';
}