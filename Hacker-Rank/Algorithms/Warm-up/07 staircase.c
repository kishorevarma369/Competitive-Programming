/*

      Question :-

          https://www.hackerrank.com/challenges/staircase

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    for(int i=0;i<n;i++)
    {
      s[i]='#';
      s[i+1]='\0';
      printf("%*s\n",n,s);
    }
    return 0;
}
