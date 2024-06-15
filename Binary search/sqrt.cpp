#include<iostream>
using namespace std;

    int mySqrt(int x) {

        int s = 0, e = x ,ans=-1;
        long long int mid;
        
            while (s <= e) {
                mid = s + ((e - s) / 2);
                if ((mid * mid) == x)
                    return mid;

                else if ((mid * mid) > x)
                    e = mid-1;

                else
                    {s = mid + 1; ans=mid;}
            }
            return ans;
        
    }

int main()
{
    int x;
    cout<<"enter number"<<endl;
    cin>>x;
    cout<<mySqrt(x);
}