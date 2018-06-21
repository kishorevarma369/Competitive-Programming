#include<bits/stdc++.h>
using namespace std;

unsigned long long int cou[65536];

unsigned long long int fun(unsigned int p,unsigned int q,int *pa,int *qa)
{
  int flag,i;
  unsigned long long int total=0,k;
  while(1)
  {
    cout<<"before\n";
      cout<<pa[1]<<pa[0]<<'\n';
      cout<<qa[1]<<qa[0]<<'\n';
      system("pause");
      if((pa[0]<qa[0]||pa[0]>qa[0])&&pa[1]<qa[1])
      {
        cout<<"act 0\n";
        total+=(65536-pa[0])*cou[pa[1]]+cou[65535];
        pa[0]=0;
        pa[1]++;
        p+=65535;
      }
      else if(pa[0]<qa[0]&&pa[1]==qa[1])
      {
        cout<<"act 1\n";
        total+=(qa[0]-pa[0]+1)*cou[pa[1]]+cou[q];
        if(p!=0) total=total-cou[p-1];
        cout<<"act 1 end\n";
      }
      else break;
      cout<<"after\n"<<pa[1]<<pa[0]<<'\n';
      cout<<qa[1]<<qa[0]<<'\n';
      system("pause");
  }
  return total;
}

int main(int argc, char const *argv[])
{
  int n,p,q,i,j,k=2,pa[2],qa[2];
  unsigned long long int total=0,t,t1;
  int mask=65535;
  cou[1]=1;
  for(i=2;i<65536;k=k<<1)
  {
    for(j=0;j<k;j++,i++)
    {
      cou[i]=cou[j]+1;
    }
  }
  for(j=1;j<65536;j++)
  {
    cou[j]+=cou[j-1];
  }
  cin>>n;
  while(n--)
  {
    cin>>p>>q;
    total=0;
    if(p<0&&q>=0)
    {
      t=(unsigned long long int)p;
      t1=~0;
      for(i=0;i<2;i++)
      {
        t=t>>(16*i);
        pa[i]=t&mask;
        qa[i]=mask;
      }
      total=fun(p,t1,pa,qa);
      p=0;
    }
    t=p;
    t1=q;
    for(i=0;i<2;i++)
    {
      t=t>>(16*i);
      t1=t1>>(16*i);
      pa[i]=t&mask;
      qa[i]=t1&mask;
    }
    total+=fun(p,q,pa,qa);
    cout<<total<<'\n';
  }
  return 0;
}
