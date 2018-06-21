/*

      Question :-

          https://www.hackerrank.com/challenges/simple-array-sum

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include <stdio.h>

int main() {
    int n,val=0,sum=0;
    scanf("%i", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        sum+=val;
    }
    printf("%d\n", sum);
    return 0;
}
