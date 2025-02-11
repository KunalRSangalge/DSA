#include<bits/stdc++.h>
using namespace std;
struct info{
    int open,close,full;
    info(){}
    info(int o,int c,int f){
        open=o;
        close=c;
        full=f;
    }
};
info merging(info seg[],int i,int j){
    int full = min(seg[i].open,seg[j].close);
    int full2 = seg[i].full+seg[j].full+full;
    int open = seg[i].open+seg[j].open-full;
    int close = seg[i].close+seg[j].close-full;
    info temp(open,close,full2);
    return temp;
}
void build(int ind,int low,int high,string&s,info seg[]){
    if(low==high){
        seg[ind] = info(s[low]=='(',s[low]==')',0);
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,s,seg);
    build(2*ind+2,mid+1,high,s,seg);
    seg[ind]=merging(seg,2*ind+1,2*ind+2);
}
int query(int ind,int low,int high,int l,int r,info seg[]){
    //complete overlap
    if(l<=low && high<=r){
        return seg[ind].full;
    }
    //no overlap
    else if(high<l || r<low){
        return 0;
    }
    //partial overlap
    else{
        int mid = (low+high)/2;
        int left = query(2*ind+1,low,mid,l,r,seg);
        int right = query(2*ind+2,mid+1,high,l,r,seg);
        return left+right;
    }
}
info merging1(info left,info right){
    info ans(0,0,0);
    ans.full = left.full+right.full + min(left.open,right.close);
    ans.close = left.close+right.close - min(left.open,right.close);
    ans.open = left.open+right.open - min(left.open,right.close);
    return ans;
}
info query1(int ind,int low,int high,int l,int r,info seg[]){
    //complete overlap
    if(l<=low && high<=r){
        return seg[ind];
    }
    //no overlap
    else if(high<l || r<low){
        info temp(0,0,0);
        return temp;
    }
    //partial overlap
    else{
        int mid=(high+low)/2;
        info left = query1(2*ind+1,low,mid,l,r,seg);
        info right = query1(2*ind+2,mid+1,high,l,r,seg);
        return merging1(left,right);
    }
}
int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    int n = s.size();
    info seg[4*n+1];
    build(0,0,n-1,s,seg);
    // cout<<seg[0].full;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        info ans = query1(0,0,n-1,l,r,seg);
        cout<<ans.full*2<<endl;
    }
}