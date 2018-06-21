#include<bits/stdc++.h>
using namespace std;

int cou[256];

unsigned long long int fun(int p,int q,int *pa)
{
  int flag,i;
  unsigned long long int total=0;
  while(p<=q)
  {
    flag=1;
    for(i=0;i<4;i++)
    {
      total+=cou[pa[i]];
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
  return total;
}

int main(int argc, char const *argv[])
{
  int n,p,q,i,j,k=2,pa[4],t;
  unsigned long long int total=0;
  int mask=255;
  cou[1]=1;
  for(i=2;i<256;k=k<<1)
  {
    for(j=0;j<k;j++)
    {
      cou[i++]=cou[j]+1;
    }
  }
  cin>>n;
  while(n--)
  {
    cin>>p>>q;
    total=0;
    if(p<0)
    {
      p=-p;
      t=p;
      p--;
      cout<<t<<'\n';
      for(i=0;i<4;i++)
      {
        t=t>>(8*i);
        pa[i]=t&mask;
      }
      total+=32*(p+1)-fun(0,p,pa);
      p=0;
    }
    t=p;
    for(i=0;i<4;i++)
    {
      t=t>>(8*i);
      pa[i]=t&mask;
    }
    total+=fun(p,q,pa);
    cout<<total<<'\n';
  }
  return 0;
}
