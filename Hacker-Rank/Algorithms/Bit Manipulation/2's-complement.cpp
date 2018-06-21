#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  unsigned int con=1<<16+1,con1=11111111111111111b;
  unsigned int a[con],i,j,k=2;
  a[0]=0;
  a[1]=1;
  for(i=2;i<con;k=k<<1)
  {
    for(j=0;j<k;j++)
    {
      a[i++]=a[j]+1;
    }
  }
  int p,q,n,lb,ub,ubcount,t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&p,&q);
    if(p<0)
    {
      p=~p+1;
      ub=p>>16;
      ubcount=32-a[ub];
      lb=p&con1;
      while(p>0)
      {
        count+=ubcount+
      }
    }

  }

  return 0;
}
