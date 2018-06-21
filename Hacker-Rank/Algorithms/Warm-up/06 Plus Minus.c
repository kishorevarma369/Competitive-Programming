/*

      Question :-

          https://www.hackerrank.com/challenges/plus-minus

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int i,val,pos=0,neg=0,zero=0;
  for(i=0;i<n;i++)
  {
    scanf("%d",&val);
    if(val>0) pos++;
    else if(val<0) neg++;
    else zero++;
  }
  printf("%.6lf\n%.6lf\n%.6lf",(double)pos/n,(double)neg/n,(double)zero/n);
    return 0;
}
