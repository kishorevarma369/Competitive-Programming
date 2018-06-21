/*

      Question :-

          https://www.hackerrank.com/challenges/a-very-big-sum

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include <stdio.h>

int main() {
    int n,i;
    unsigned long long int sum=0;
    scanf("%i", &n);
    unsigned long long int ar;
    for(i=0;i<n;i++)
    {
       scanf("%llu",&ar);
       sum+=ar;
    }
    printf("%llu\n", sum);
    return 0;
}
