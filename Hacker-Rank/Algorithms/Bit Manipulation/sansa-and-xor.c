#include<stdio.h>
#include<stdlib.h>
void fun()
{
  int n,i=0;
  unsigned long long int j,k=0;
  scanf("%d",&n);
  if(n&1)
  {
    for(i=0;i<n;i++)
    {
      scanf("%llu",&j);
      if((i&1)==0)
      {
        k^=j;
      }
    }
  }
  else for(i=0;i<n;i++) scanf("%llu",&j);
  printf("%llu\n",k);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
