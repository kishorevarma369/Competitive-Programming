#include<stdio.h>
typedef unsigned long long int uul;
//fails 6 test cases need to find better solution
//just time limit exceeded
void fun()
{
  long long int n,i,j,max=0,m,t;
  scanf("%lld %lld",&n,&m);
  long long int a[n+2];
  a[0]=a[n+1]=0;
  for(i=1;i<=n;i++)
  {
    scanf("%lld",&t);
    a[i]=(a[i-1]+t)%m;
  }
  for(i=1;i<=n;i++)
  {
    for(j=i;j<=n;j++)
    {
      t=a[j]-a[j-i];
      if(t<0) t+=m;
      if(t>max) max=t;
    }
    if(max==m-1) break;
  }
  printf("%lld\n",max);
}

int main(int argc, char const *argv[])
{
   int n;
   scanf("%d",&n);
   while(n--) fun();
  return 0;
}
