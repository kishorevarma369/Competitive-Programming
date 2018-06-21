#include<stdio.h>
int main()
{
  int a[10001],n,i,m=2,flag=0,j;
  scanf("%d",&n);
  for(i=0;i<n-1;i++)
  {
  a[i]=m;
  m++;
  }
  for(i=0;i<n-1;i++)
  {
    if(a[i]!=0)
    {
    m=a[i];
    for(j=0;j<n;j++)
    if(a[j]%m==0)
    a[j]=0;
    if(flag==0)
    flag=1;
    else
    flag=0;
  }
  }
  if(flag==1)
  printf("Raman");
  else
  printf("Lakshman");

  return 0;
}
