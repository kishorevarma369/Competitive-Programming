#include<stdio.h>

typedef unsigned long long int uul;

int a[10000001];

inline int iseven(uul x)
{
  return x&1?0:1;
}

inline int isodd(uul x)
{
  return x&1?1:0;
}

void generate()
{
  int i=0;
  for(;i<10000001;i++) a[i]=a[i-1]^i;
}

void fun()
{
  uul x=0,low,upper;
  scanf("%llu %llu",&low,&upper);
  if(((isodd(low))&&(iseven(upper)))||(isodd(upper)&&iseven(low)))
  {
    if(upper<10000001)
    {
      printf("%llu\n",a[upper]^a[low-1]);
      return ;
    }
    while(upper>=low)
    {
      if(upper<10000001)
      {
        printf("%llu\n",x^a[upper]^a[low-1]);
        return ;
      }
      x^=upper;
      upper-=2;
    }
    printf("%llu\n",x);
    return;
  }
  while(upper>low)
  {
    x^=upper;
    upper-=2;
  }
  while(upper!=0)
  {
    if(upper<=10000000)
    {
      x^=a[upper];
      printf("%llu\n",x);
      return;
    }
    x^=upper;
    upper--;
  }
  printf("%llu\n",x);
  return;
}

int main(int argc, char const *argv[])
{
  generate();
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
