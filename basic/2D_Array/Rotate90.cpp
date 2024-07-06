#include<iostream>
using namespace std;

int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    int i=3,j=3;
    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        swap(matrix[i][j],matrix[j][i]);
    }
    int jmin=0,jmax=2;
    if(j%2!=0)
    {
        while(jmin<(j/2)){
            int i=0;
            while(i<3){            
                swap(matrix[i][jmin],matrix[i][jmax]);
                i++;
            }
            jmin++;
            jmax--;
        }
    }
    else
    {
        while(jmin<=(j/2)){
            int i=0;
            while(i<3){
                swap(matrix[i][jmin],matrix[i][jmax]);
                i++;
            }
            jmin++;
            jmax--;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cout<<matrix[i][j]<<' ';
        cout<<endl;
    }
}