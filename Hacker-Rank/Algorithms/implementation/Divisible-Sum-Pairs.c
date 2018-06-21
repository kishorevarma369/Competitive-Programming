#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,k,i,j,count=0;
  scanf("%d %d",&n,&k);
  int a[n];
  for (i = 0; i < n; i++) scanf("%d",a+i);
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if((a[i]+a[j])%k==0) count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
