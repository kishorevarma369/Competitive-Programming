#include<bits/stdc++.h>
using namespace std;

int count[255];

int fun(int p,int q)
{
  while(p<=q)
  {
    flag=1;
    for(i=0;i<4;i++)
    {
      total+=count[pa[i]];
      if(flag)
      {
        pa[i]+=1;
        if(pa[i]==255)
        {
          pa[i]=0;
          flag++;
        }
        flag--;
      }
    }
    p++;
  }
}

int main(int argc, char const *argv[])
{
  int n,p,q,i,j,k=2,count[256],pa[4],t,flag,total;
  int mask=255;
  count[0]=0;
  count[1]=1;
  for(i=2;i<256;k=k<<1)
  {
    for(j=0;j<k;j++)
    {
      count[i++]=count[j]+1;
    }
  }
  cin>>n;
  while(n--)
  {
    cin>>p>>q;
    if(p<0)
    {
      p=~p+1;
      t=p;
      for(i=0;i<4;i++)
      {
        t=t>>(8*i);
        pa[i]=t&mask;
      }
      fun(0,p);
    }
    total=0;
    for(i=0;i<4;i++)
    {
      t=t>>(8*i);
      pa[i]=t&mask;
    }
    cout<<total<<'\n';
  }
  return 0;
}
