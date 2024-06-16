#include<iostream>
using namespace std;

    int searchInsert(int nums[], int n, int target) {
        int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid=(start+end)/2;

            if(nums[mid]==target)
            return mid;

            else if(target>nums[mid])
            start=mid+1;

            else
            end=mid-1;
        }
        start=0;
        end=n-1;
        while(start<=end)
        {
            mid=(start+end)/2;

            if(nums[mid]<target)
            start=mid+1;
            else
            end=mid-1; 
        }
        return end+1;
    }

int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"enter key";
    int target;
    cin>>target;
   cout<<searchInsert(a,n,target);
}