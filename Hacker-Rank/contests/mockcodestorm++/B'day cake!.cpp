/*
https://www.hackerrank.com/contests/mockcodestorm++/challenges/bday-cake

Karna wants to present a cake to his friend,the shop nearby has only two flavours(X,O).He wants to order a cake of dimensions(m,n) such that m be the number of boys attended,n be the number of girls attended for that party.

Note:

Outer layer must be 'X'

He wants the cake to be colorful so that two same flavours(layers) should not be adjacent.

Design a cake for him in the given dimensions with the given flavours(X,O).

*/

#include<stdio.h>
#define min(m,n) m>n?n:m
int main(int argc, char const *argv[])
{
  int m,n,i,j,k,p,flag=1;
  scanf("%d %d",&m,&n);
  char a[m][n],s[]="XO";
  p=min(m,n);
  if(p&1) p=p/2+1;
  else p/=2;
  for(i=0;i<p;i++)
  {
    if(flag) flag=0;
    else flag=1;
    for(j=i;j<m-i;j++)
    {
      for(k=i;k<n-i;k++) a[j][k]=s[flag];
    }
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++) printf("%c ",a[i][j]);
    putchar('\n');
  }
  return 0;
}
