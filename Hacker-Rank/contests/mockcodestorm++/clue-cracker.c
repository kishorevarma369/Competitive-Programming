#include<stdio.h>
#include<conio.h>
void main()
{
  int n,sum=0;
  scanf("%d",&n);
  while(n>0)
  {
    while(n!=0)
    {
     sum=sum+n%10;
     n=n/10;
    }
    if(sum>9)
    {
    n=sum;
    sum=0;
    }
  printf("%d",sum);
}
