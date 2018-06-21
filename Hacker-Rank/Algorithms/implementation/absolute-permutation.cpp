#include<bits/stdc++.h>
using namespace std;

int valid(int n,int k)
{
  if(k==0) return 1;
  return n%(2*k)==0;
}

void fun()
{
  int n,k,i,j,val=1,l;
  cin>>n>>k;
  int a[n];
  if(valid(n,k))
  {
    if(k==0)
    {
      for(i=0;i<n;i++) cout<<i+1<<' ';
      cout<<'\n';
      return;
    }
    for(i=k;i<n;i+=2*k)
    {
      l=i+k;
      for(j=i;j<l;j++)
      {
        a[j]=val++;
      }
      l=i-k;
      for(j=l;j<i;j++)
      {
        a[j]=val++;
      }
    }
    for(i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<'\n';
    return;
  }
  cout<<"-1\n";
}

int main(int argc, char const *argv[])
{
 int n;
 cin>>n;
 while(n--) fun();
  return 0;
}
