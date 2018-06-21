#include<stdio.h>
#include<stdlib.h>
void fun()
{
  int n,i,count=0,j,flag=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    if(a[i]-(i+1)>2) flag=1;
  }
  if(flag)
  {
    printf("Too chaotic\n");
    return;
  }
  for(i=0;i<n-1;i++)
  {
    flag=1;
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        flag=0;
        a[j]=a[j+1]+a[j]-(a[j+1]=a[j]);
        count++;
      }
    }
    if(flag) break;
  }
  printf("%d\n",count);
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
