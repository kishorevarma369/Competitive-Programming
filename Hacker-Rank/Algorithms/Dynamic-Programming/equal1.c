#include<stdio.h>

void fun()
{
  int n,i,min=1000,count=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    if(a[i]<min) min=a[i];
  }
  for(i=0;i<n;i++)
  {
    while(a[i]>min)
    {
      if(a[i]-5>=min)
      {
        a[i]-=5;
        count++;
      }
      else
      {
        if(a[i]-2>=min)
        {
            a[i]-=2;
            count++;
        }
        else
        {
          if(a[i]-1>=min)
          {
            a[i]-=1;
            count++;
          }
        }
      }
    }
  }
  printf("%d\n",count);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
