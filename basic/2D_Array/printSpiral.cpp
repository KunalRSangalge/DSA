#include<iostream>
#include<vector>
using namespace std;

int main(){
    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int a[13];
    int i=0,j=0,jmin=0,imin=0,jmax=4,imax=3,k=0;

    while(k<12){
        for(;j<jmax;j++){
            a[k]=matrix[i][j]; k++;
        }
        j--;
        jmax--;
        i++;

        for(;i<imax;i++){
            a[k]=matrix[i][j]; k++;
        }
        i--;
        imax--;
        j--;

        for(;j>=jmin;j--){
            a[k]=matrix[i][j]; k++;
        }
        j++;
        jmin++;
        i--;

        for(;i>imin;i--){
            a[k]=matrix[i][j]; k++;
        }
        i++;
        imin++;
        j++;
        cout<<i<<j<<k<<endl;
    }
    for(int i=0;i<13;i++)
    cout<<a[i]<<' ';
}