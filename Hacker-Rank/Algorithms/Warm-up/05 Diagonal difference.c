/*

      Question :-

        https://www.hackerrank.com/challenges/diagonal-difference

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include <stdio.h>

int main(){
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){

          scanf("%d",&a[a_i][a_j]);
       }
    }
    int sum=0,sum1=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j) sum+=a[i][j];
            if(i==n-j-1||j==n-i-1) sum1+=a[i][j];
        }
    }
    printf("%d",sum>sum1?sum-sum1:sum1-sum);
    return 0;
}
