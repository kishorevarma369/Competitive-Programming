#include<stdio.h>

typedef unsigned long long int uul;

uul v[64];

void generate()
{
  uul b=1;
  for(int i=0;i<64;i++) v[i]=b<<i;
}

uul minval(uul val)
{
  int pos=63;
  if(val==1) return 1;
  while(v[pos]>val) pos/=2;
  while(v[pos]<val) pos++;
  return v[pos-1];
}

void fun()
{
  int flag=0;
  uul n;
  scanf("%llu",&n);
  while(n!=1)
  {
    n-=minval(n);
    if(flag) flag=0;
    else flag=1;
  }
  if(flag) printf("Louise\n");
  else printf("Richard\n");
}

int main(int argc, char const *argv[])
{
  generate();
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
