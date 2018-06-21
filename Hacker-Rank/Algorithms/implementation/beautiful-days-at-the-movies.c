#include<stdio.h>

int fun(int n)
{
  int val=0;
  while(n!=0)
  {
    val=val*10+n%10;
    n/=10;
  }
  return val;
}

int main(int argc, char const *argv[]) {
  int a,b,k,tmp,count=0;
  scanf("%d %d %d",&a,&b,&k);
  for(;a<=b;a++)
  {
    tmp=reverse(a);
    if(abs(a-tmp)%k==0) count++;
  }
  printf("%d\n",count);
  return 0;
}
