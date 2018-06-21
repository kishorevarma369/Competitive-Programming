#include<stdio.h>
typedef unsigned long long int uul;

void fun()
{
  int n,i,j;
  scanf("%d",&n);
  unsigned long long int sum=0,a[n+2],m;
  for(i=1;i<=n;i++) {
    scanf("%llu",&m);
    a[i]=(sum+=m);
  }
  a[0]=a[n+1]=0;
  for(i=1;i<=n;i++)
  {
    if(a[n]-a[i]==a[i-1]) break;
  }
  if(i==n+1)
  {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main(int argc, char const *argv[])
{
   int n;
   scanf("%d",&n);
   while(n--) fun();
  return 0;
}
