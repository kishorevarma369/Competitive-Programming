#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,i=0,count=0;
  scanf("%d",&n);
  int a[n+2];
  for(i=0;i<n;i++) scanf("%d",a+i);
  a[n]=a[n+1]=1;
  for(i=0;i<n;i++)
  {
    if(a[i]==0)
    {
      if(a[i+1]==0)
      {
        if(a[i+2]==0) i++;
        count++;
      }
      else
      {
        if(a[i+2]==0)
        {
          count++;
          i++;
        }
        else break;
      }
    }
    else break;
  }
  printf("%d\n",count);
  return 0;
}
